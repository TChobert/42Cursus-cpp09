#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>

#include "PMergeme.hpp"

int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe [numbers]" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int> valuesVec;
	std::vector<int> result;

	if (!PMergeme::parseInput(ac - 1, av + 1, valuesVec))
		return (EXIT_FAILURE);

	result = PMergeme::sortVector(valuesVec);
	//std::deque<int> valuesDeq(valuesVec.begin(), valuesVec.end());

	return (EXIT_SUCCESS);
}
