#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>

int printError(std::string message) {

	if (!(message.empty()))
		std::cerr << "Error: " << message << std::endl;
	else
		std::cerr << "Error" << std::endl;
	return (EXIT_FAILURE);
}

bool willAddOverflow(int a, int b) {

	return (b > 0 && a > std::numeric_limits<int>::max() - b) ||
		(b < 0 && a < std::numeric_limits<int>::min() - b);
}

bool willSubOverflow(int a, int b) {

	return (b > 0 && a < std::numeric_limits<int>::min() + b) ||
		(b < 0 && a > std::numeric_limits<int>::max() + b);
}

bool willMulOverflow(int a, int b) {

	if (a == 0 || b == 0)
		return (false);
	if (a == -1 && b == std::numeric_limits<int>::min())
		return (true);
	if (b == -1 && a == std::numeric_limits<int>::min())
		return (true);

	return (a > std::numeric_limits<int>::max() / b) ||
		(a < std::numeric_limits<int>::min() / b);
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
			double res = 0;

			if (token == "+") {
				if (willAddOverflow(a, b))
					return printError("Overflow in addition.");
				res = a + b;
			}
			else if (token == "-") {
				if (willSubOverflow(a, b))
					return printError("Overflow in subtraction.");
				res = a - b;
			}
			else if (token == "*") {
				if (willMulOverflow(a, b))
					return printError("Overflow in multiplication.");
				res = a * b;
			}
			else {
				if (b == 0) {
					return (printError("division by 0."));
				}
				res = a / b;
			}

			if (res > std::numeric_limits<int>::max()) {
				return (printError("Overflow in resultat."));
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

	return (EXIT_SUCCESS);
}
