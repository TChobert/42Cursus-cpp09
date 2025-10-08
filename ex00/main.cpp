#include <iostream>
#include <cstdlib>

#include "DatabaseLoader.hpp"
#include "DatabaseParser.hpp"
#include "InputFileLoader.hpp"
#include "InputFileParser.hpp"
#include "ValuesCalculator.hpp"

#define DATABASE_PATH "./data.csv"

int main (int ac, char **av) {

	if (ac != 2) {
		std::cerr << "Error! Usage: ./btc <input file>" << std::endl;
		return (EXIT_FAILURE);
	}

	std::map<std::string, double> inputFileValues;
	std::map<std::string, double> dataBaseValues;

	InputFileParser IFparser;
	InputFileLoader IFloader(IFparser);
	DatabaseParser DBparser;
	DatabaseLoader DBloader(DBparser);

	try {
		inputFileValues = IFloader.loadInput(av[1]);
		dataBaseValues = DBloader.loadDatabase(DATABASE_PATH);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	ValuesCalculator calculator;
	calculator.calculateValues(dataBaseValues, inputFileValues);

	return (EXIT_SUCCESS);
}
