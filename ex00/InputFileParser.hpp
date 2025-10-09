#pragma once

#include "IParser.hpp"

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>

class InputFileParser : public IParser {

	private:

	InputFileParser(const InputFileParser& other);
	InputFileParser& operator=(const InputFileParser& other);
	bool isValidDate(const std::string& dateStr) const;
	bool isValidValue(const std::string& value) const;

	public:

	InputFileParser(void);
	~InputFileParser(void);

	bool checkYearValue(const std::string& yearStr, const std::string& monthStr, const std::string& dayStr) const;
	bool checkMonthValue(const std::string& monthStr, const std::string& dayStr, bool isLeap) const;
	bool checkDayValue(const std::string& dayStr, int month, bool isLeap) const;
};
