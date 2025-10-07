#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Sorter {

	public:

	Sorter(void);
	Sorter(const Sorter& other);
	Sorter& operator=(const Sorter& other);
	~Sorter(void);

	static std::vector<size_t> generateJacobsthalOrder(size_t size);
	static std::vector<int> sortVector(std::vector<int>& valuesVec);
//	static void sortDeque(std::deque<int>& valuesDeq);
};
