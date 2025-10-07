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

	if (!PMergeme::parseInput(ac - 1, av + 1, valuesVec))
		return (EXIT_FAILURE);

	std::deque<int> valuesDeq(valuesVec.begin(), valuesVec.end());
	std::deque<int> resultDeq;
	std::vector<int> resultVec;

	resultVec = PMergeme::sortVector(valuesVec);
	resultDeq = PMergeme::sortDeque(valuesDeq);

	return (EXIT_SUCCESS);
}
