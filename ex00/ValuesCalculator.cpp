#include "ValuesCalculator.hpp"

ValuesCalculator::ValuesCalculator(void) {}

ValuesCalculator::ValuesCalculator(const ValuesCalculator& other) {
	(void)other;
}

ValuesCalculator& ValuesCalculator::operator=(const ValuesCalculator& other) {
	if (this != &other) {}
	return (*this);
}

ValuesCalculator::~ValuesCalculator(void) {}

void ValuesCalculator::calculateValues(const std::map<std::string, double>& databaseValues, const std::map<std::string, double>& inputFileValues) const {

	for (std::map<std::string, double>::const_iterator it = inputFileValues.begin(); it != inputFileValues.end(); ++it) {

		const std::string date = it->first;
		double amount = it->second;

		std::map<std::string,double>::const_iterator dbIt = databaseValues.lower_bound(date);

		if (dbIt == databaseValues.begin() && dbIt->first > date) {
			std::cerr << "No bitcoin price available before " << date << std::endl;
			continue;
		}
		if (dbIt == databaseValues.end() || dbIt->first > date) {
			--dbIt;
		}

		double btcValue = dbIt->second;
		double result = amount * btcValue;

		std::cout << std::fixed << std::setprecision(2);
		std::cout << BRIGHT_YELLOW << date << " => " << amount << " = " << result << RESET << std::endl;
	}
}
