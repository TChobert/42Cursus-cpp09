#pragma once

#include <map>
#include <iostream>
#include <algorithm>
#include <exception>
#include <cstdlib>
#include <iomanip>

#define BRIGHT_YELLOW "\033[93m"
#define RESET "\033[0m"

class ValuesCalculator {

	public:

	ValuesCalculator(void);
	ValuesCalculator(const ValuesCalculator& other);
	ValuesCalculator& operator=(const ValuesCalculator& other);
	~ValuesCalculator(void);

	void calculateValues(const std::map<std::string, double>& databaseValues, const std::map<std::string, double>& inputFileValues) const;
};
