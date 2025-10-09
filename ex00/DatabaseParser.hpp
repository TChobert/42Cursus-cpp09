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

	DatabaseParser(const DatabaseParser& other);
	DatabaseParser& operator=(const DatabaseParser& other);
	bool checkYearValue(const std::string& yearStr, const std::string& monthStr, const std::string& dayStr) const;
	bool checkMonthValue(const std::string& monthStr, const std::string& dayStr, bool isLeap) const;
	bool checkDayValue(const std::string& dayStr, int month, bool isLeap) const;

	public:

	DatabaseParser(void);
	~DatabaseParser(void);

	bool isValidDate(const std::string& dateStr) const;
	bool isValidValue(const std::string& valueStr) const;
};
