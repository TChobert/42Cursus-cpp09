#pragma once

#include <string>
#include <ctype.h>
#include <set>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <limits>

class InputParser {

	public:

	InputParser(void);
	InputParser(const InputParser& other);
	InputParser& operator=(const InputParser& other);
	~InputParser(void);

	static bool parseInput(int argsNb, char **args, std::vector<int>& numbers);
};
