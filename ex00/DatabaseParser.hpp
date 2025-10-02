#pragma once

#include "IParser.hpp"

#include <map>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <exception>

class DatabaseParser : public IParser {

	private:

	bool checkYearValue(const std::string& yearStr);
	bool checkMonthValue(const std::string& yearStr);
	bool checkDayValue(const std::string& yearStr);

	public:

	DatabaseParser(void);
	DatabaseParser(const DatabaseParser& other);
	~DatabaseParser(void);
	DatabaseParser& operator=(const DatabaseParser& other);

	bool isValidDate(const std::string& dateStr);
	bool isValidValue(const std::string& valueStr);
};
