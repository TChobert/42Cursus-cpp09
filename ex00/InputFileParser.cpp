#include "InputFileParser.hpp"

InputFileParser::InputFileParser(void) {}

InputFileParser::InputFileParser(const InputFileParser& other) {
	(void)other;
}

InputFileParser& InputFileParser::operator=(const InputFileParser& other) {
	if (this != &other) {}
	return (*this);
}

InputFileParser::~InputFileParser(void) {}

bool InputFileParser::checkDayValue(const std::string& dayStr) const {

	if (dayStr.length() != 2)
		return (false);

	char *end = NULL;
	long value = strtol(dayStr.c_str(), &end, 10);

	if (*end != '\0' || value <= 0 || value > 31)
		return (false);
	return (true);
}

bool InputFileParser::checkMonthValue(const std::string& monthStr) const {

	if (monthStr.length() != 2)
		return false;

	char *end = NULL;
	long value = strtol(monthStr.c_str(), &end, 10);

	if (*end != '\0' || value <= 0 || value > 12)
		return (false);
	return (true);
}

bool InputFileParser::checkYearValue(const std::string& yearStr) const {

	if (yearStr.length() != 4)
		return (false);

	char *end = NULL;
	double value = strtod(yearStr.c_str(), &end);

	if (*end != '\0' || value <= 0) {
		if (value < 0) {
			std::cerr << "Error. Negative value. ";
		}
		return (false);
	}
	return (true);
}

bool InputFileParser::isValidDate(const std::string& dateStr) const {

	std::string yearStr, monthStr, dayStr;
	std::stringstream ss(dateStr);

	if (std::getline(ss, yearStr, '-') && std::getline(ss, monthStr, '-') && std::getline(ss, dayStr)) {

		if (!checkYearValue(yearStr) || !checkMonthValue(monthStr) || !checkDayValue(dayStr))
			return (false);
		return (true);
	}
	return (false);
}

bool InputFileParser::isValidValue(const std::string& valueStr) const {

	char *end = NULL;
	double value = strtod(valueStr.c_str(), &end);

	if (*end != '\0' || value < 0 || value > 1000) {
		return (false);
	}
	return (true);
}
