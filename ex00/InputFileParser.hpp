#pragma once

#include "IParser.hpp"

#include <iostream>
#include <string>
#include <map>
#include <sstream>

class InputFileParser : public IParser {

	private:

	InputFileParser(void);
	InputFileParser(const InputFileParser& other);
	InputFileParser& operator=(const InputFileParser& other);
	~InputFileParser(void);

	bool checkYearValue(const std::string& yearStr);
	bool checkMonthValue(const std::string& monthStr);
	bool checkDayValue(const std::string& dayStr);

	public:

	bool isValidDate(const std::string& dateStr);
	bool isValidValue(const std::string& value);
};
