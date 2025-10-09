#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>

#include "PmergeMe.hpp"

long getTimeMicroseconds()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000L + tv.tv_usec;
}

int main(int ac, char **av) {

	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe [numbers]" << std::endl;
		return (EXIT_FAILURE);
	}

	std::vector<int> valuesVec;

	if (!PmergeMe::parseInput(ac - 1, av + 1, valuesVec))
		return (EXIT_FAILURE);

	PmergeMe::printSequenceVec("Before", valuesVec);
	std::deque<int> valuesDeq(valuesVec.begin(), valuesVec.end());
	std::deque<int> resultDeq;
	std::vector<int> resultVec;

	long startVec = getTimeMicroseconds();
	resultVec = PmergeMe::sortVector(valuesVec);
	long endVec = getTimeMicroseconds();
	double timeVec = static_cast<double>(endVec - startVec);

	long startDeq = getTimeMicroseconds();
	resultDeq = PmergeMe::sortDeque(valuesDeq);
	long endDeq = getTimeMicroseconds();
	double timeDeq = static_cast<double>(endDeq - startDeq);

	PmergeMe::printSequenceVec("After", resultVec);
	PmergeMe::printTime("vector", resultVec.size(), timeVec);
	PmergeMe::printTime("deque", resultDeq.size(), timeDeq);

	return (EXIT_SUCCESS);
}
