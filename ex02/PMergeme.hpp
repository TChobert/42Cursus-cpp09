#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <limits>
#include <iomanip>

class PMergeme {

	public:

	PMergeme(void);
	PMergeme(const PMergeme& other);
	PMergeme& operator=(const PMergeme& other);
	~PMergeme(void);

	static void printSequenceDeq(const std::string& label, const std::deque<int>& deq);
	static void printSequenceVec(const std::string& label, const std::vector<int>& vec);
	static void printTime(const std::string& containerName, size_t size, double time);
	static bool parseInput(int argsNb, char **args, std::vector<int>& numbers);
	static std::vector<size_t> generateJacobsthalOrderVector(size_t size);
	static std::deque<size_t> generateJacobsthalOrderDeque(size_t size);
	static std::vector<int> sortVector(std::vector<int>& valuesVec);
	static std::deque<int> sortDeque(std::deque<int>& valuesDeq);
};
