#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <limits>

class PMergeme {

	public:

	PMergeme(void);
	PMergeme(const PMergeme& other);
	PMergeme& operator=(const PMergeme& other);
	~PMergeme(void);

	static bool parseInput(int argsNb, char **args, std::vector<int>& numbers);
	static std::vector<size_t> generateJacobsthalOrderVector(size_t size);
	static std::deque<size_t> generateJacobsthalOrderDeque(size_t size);
	static std::vector<int> sortVector(std::vector<int>& valuesVec);
	static std::deque<int> sortDeque(std::deque<int>& valuesDeq);
};
