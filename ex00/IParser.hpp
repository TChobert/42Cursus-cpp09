#pragma once

#include <string>

class IParser {

	public:

	virtual ~IParser(void);
	virtual bool isValidDate(const std::string& date) const = 0;
	virtual bool isValidValue(const std::string& value) const = 0;
};
