#include "InputParser.hpp"

InputParser::InputParser(void) {}

InputParser::InputParser(const InputParser& other) {
	(void)other;
}

InputParser& InputParser::operator=(const InputParser& other) {
	if (this != &other) {}
	return (*this);
}

InputParser::~InputParser(void) {}

bool InputParser::parseInput(int argsNb, char **args, std::vector<int>& numbers) {

	std::set<int> seen;

	for (int i = 0; i < argsNb; ++i) {

		char* end;
		long val = std::strtol(args[i], &end, 10);

		if (*end != '\0' || val < 0 || val > std::numeric_limits<int>::max()) {
			std::cerr << "Error" << std::endl;
			return (false);
		}

		if (!seen.insert(static_cast<int>(val)).second) {
			std::cerr << "Error" << std::endl;
			return (false);
		}

		numbers.push_back(static_cast<int>(val));
	}

	return (true);
}

