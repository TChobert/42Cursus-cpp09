#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>

int printError(std::string message) {

	if (!(message.empty()))
		std::cerr << "Error: " << message << std::endl;
	else
		std::cerr << "Error" << std::endl;
	return (EXIT_FAILURE);
}

bool isNumber(const std::string& token) {

	if (token.empty())
		return false;

	size_t i = (token[0] == '-' || token[0] == '+');
	while (i < token.size()) {
		if (!std::isdigit(token[i]))
			return (false);
		++i;
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
				return (printError(""));
			}

			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			int res = 0;

			if (token == "+") res = a + b;
			else if (token == "-") res = a - b;
			else if (token == "*") res = a * b;
			else {
				if (b == 0) {
					return (printError("division by 0."));
				}
				res = a / b;
			}

			stack.push(res);
		
		} else if (isNumber(token)) {

			int num = std::atoi(token.c_str());
			if (num >= 10) {
				return (printError(token + " is a too large number."));
			}
			stack.push(num);
		} else {
			return (printError( token + " is not a number."));
		}
	}

	if (stack.size() != 1) {
		return (printError(""));
	}

	std::cout << stack.top() << std::endl;
	return EXIT_SUCCESS;
}
