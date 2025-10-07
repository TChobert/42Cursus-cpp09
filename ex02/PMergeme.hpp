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
	static std::vector<size_t> generateJacobsthalOrder(size_t size);
	static std::vector<int> sortVector(std::vector<int>& valuesVec);
//	static void sortDeque(std::deque<int>& valuesDeq);
};
