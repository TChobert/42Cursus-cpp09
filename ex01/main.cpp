#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>

bool isNumber(const std::string& token) {

	if (token.empty())
		return false;

	for (size_t i = 0; i < token.size(); ++i) {
		if (!std::isdigit(token[i]))
			return (false);
	}
	return (true);
}

int main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return (EXIT_FAILURE);
	}

	std::string expr = av[1];
	std::istringstream iss(expr);
	std::stack<int> stack;
	std::string token;

	while (iss >> token) {

		if (token == "+" || token == "-" || token == "*" || token == "/") {

			if (stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return (EXIT_FAILURE);
		}

			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			int res = 0;

			if (token == "+") res = a + b;
			else if (token == "-") res = a - b;
			else if (token == "*") res = a * b;
			else {
				if (b == 0) {
					std::cerr << "Error: division by 0." << std::endl;
					return (EXIT_FAILURE);
				}
				res = a / b;
			}

			stack.push(res);
		
		} else if (isNumber(token)) {

			int num = std::atoi(token.c_str());
			if (num >= 10) {
				std::cerr << "Error:" << token << " is a too large number." << std::endl;
				return (EXIT_FAILURE);
		}
			stack.push(num);
		} else {
			std::cerr << "Error " << token << " is not a number." << std::endl;
			return (EXIT_FAILURE);
		}
	}

	if (stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return (EXIT_FAILURE);
	}

	std::cout << stack.top() << std::endl;
	return EXIT_SUCCESS;
}
