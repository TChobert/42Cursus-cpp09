#include "InputFileParser.hpp"

InputFileParser::InputFileParser(void) {}

InputFileParser::InputFileParser(const InputFileParser& other) {}

InputFileParser& InputFileParser::operator=(const InputFileParser& other) {
	if (this != &other) {}
	return (*this);
}

InputFileParser::~InputFileParser(void) {}

bool InputFileParser::checkDayValue(const std::string& dayStr) {

	if (dayStr.length() != 2)
		return (false);

	char *end = NULL;
	double value = strtod(dayStr.c_str(), &end);

	if (*end != '\0' || value <= 0 || value > 31)
		return (false);
	
	return (true);
}


bool InputFileParser::checkMonthValue(const std::string& monthStr) {

	if (monthStr.length() != 2)
		return (false);

	char *end = NULL;
	double value = strtod(monthStr.c_str(), &end);

	if (*end != '\0' || value <= 0)
		return (false);
	
	return (true);
}

bool InputFileParser::checkYearValue(const std::string& yearStr) {

	if (yearStr.length() != 4)
		return (false);

	char *end = NULL;
	double value = strtod(yearStr.c_str(), &end);

	if (*end != '\0' || value <= 0)
		return (false);
	return (true);
}

bool InputFileParser::isValidDate(const std::string& dateStr) {

	std::string yearStr, monthStr, dayStr;
	char sep1, sep2;

	std::stringstream ss(dateStr);
	if (ss >> yearStr >> sep1 >> monthStr >> sep2 >> dayStr) {

		if (sep1 != '-' || sep2 != '-')
			return (false);

		if (!checkYearValue(yearStr) || !checkMonthValue(monthStr) ||!checkDayValue(dayStr))
			return (false);
	} else
		return (false);

	return (true);
}

bool InputFileParser::isValidValue(const std::string& valueStr) {

	char *end = NULL;
	double value = strtod(valueStr.c_str(), &end);

	if (*end != '\0' || value < 0 || value > 1000) {
		return (false);
	}
	return (true);
}
