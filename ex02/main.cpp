#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>

#include "InputParser.hpp"

int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe [numbers]" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int> valuesVec;

	if (!InputParser::parseInput(ac, av + 1, valuesVec))
		return (EXIT_FAILURE);

	std::deque<int> valuesDeq(valuesVec.begin(), valuesVec.end());

	return (EXIT_SUCCESS);
}
