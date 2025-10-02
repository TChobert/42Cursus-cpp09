#pragma once

#include "IParser.hpp"
#include "InputFileParser.hpp"

#include <iostream>
#include <map>
#include <cstdlib>
#include <exception>
#include <string>
#include <fstream>
#include <sstream>

class InputFileLoader {

	private:

	IParser& _parser;

	public:

	InputFileLoader(IParser& parser);
	InputFileLoader(const InputFileLoader& other);
	InputFileLoader& operator=(const InputFileLoader& other);
	~InputFileLoader(void);

	std::map<std::string, double> loadInput(const std::string& file);

	class unopenedFileException : public std::exception {
		virtual const char *what() const throw();
	};
};
