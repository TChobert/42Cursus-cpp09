#include "DatabaseParser.hpp"

DatabaseParser::DatabaseParser(void) {}

DatabaseParser::DatabaseParser(const DatabaseParser& other) {
	(void)other;
}

DatabaseParser::~DatabaseParser(void) {}

DatabaseParser& DatabaseParser::operator=(const DatabaseParser &other) {
	if (this != &other) {}
	return (*this);
}

bool DatabaseParser::checkDayValue(const std::string& dayStr, int month, bool isLeap) const {

	if (dayStr.length() < 1)
		return (false);

	char *end = NULL;
	long value = strtol(dayStr.c_str(), &end, 10);

	if (*end != '\0' || value <= 0 || value > 31)
		return (false);
	if (month == 2) {
		if (isLeap == true) {
			if (value > 29)
				return (false);
		} else {
			if (value > 28) {
				std::cerr << "Error. A non leap year cannot have a february 29 .";
				return (false);
			}
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (value > 30) {
			std::cerr << "Error. This month cannot have more than 30 days. ";
			return (false);
		}
	}
	return (true);
}

bool DatabaseParser::checkMonthValue(const std::string& monthStr, const std::string& dayStr, bool isLeap) const {

	if (monthStr.length() != 2)
		return false;

	char *end = NULL;
	long value = strtol(monthStr.c_str(), &end, 10);

	if (*end != '\0' || value <= 0 || value > 12)
		return (false);
	return (checkDayValue(dayStr, value, isLeap));
}

bool DatabaseParser::checkYearValue(const std::string& yearStr, const std::string& monthStr, const std::string& dayStr) const {

	if (yearStr.length() != 4)
		return (false);

	char *end = NULL;
	long value = strtol(yearStr.c_str(), &end, 10);

	if (*end != '\0' || value <= 0) {
		if (value < 0) {
			std::cerr << "Error. Negative value. ";
		}
		return (false);
	}
	bool isLeap = (value % 4 == 0 && (value % 100 != 0 || value % 400 == 0));
	return (checkMonthValue(monthStr, dayStr, isLeap));
}

bool DatabaseParser::isValidDate(const std::string& dateStr) const {

	std::string yearStr, monthStr, dayStr;
	std::stringstream ss(dateStr);

	if (std::getline(ss, yearStr, '-') && std::getline(ss, monthStr, '-') && std::getline(ss, dayStr)) {

		if (!checkYearValue(yearStr, monthStr, dayStr))
			return (false);
		return (true);
	}
	return (false);
}

bool DatabaseParser::isValidValue(const std::string& valueStr) const {

	if (valueStr.empty())
		return (false);
	char *end = NULL;
	double value = strtod(valueStr.c_str(), &end);

	if (*end != '\0' || value < 0) {
		return (false);
	}
	return (true);
}
