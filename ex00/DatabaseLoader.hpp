#pragma once

#include "IParser.hpp"
#include "DatabaseParser.hpp"

#include <iostream>
#include <map>
#include <cstdlib>
#include <exception>
#include <string>
#include <fstream>
#include <sstream>

#define SPACE ' '

class DatabaseLoader {

	private:

	void trimSpaces(std::string& str);
	IParser& _DBparser;

	public:

	DatabaseLoader(IParser& DBparser);
	DatabaseLoader(const DatabaseLoader& other);
	DatabaseLoader& operator=(const DatabaseLoader& other);
	~DatabaseLoader(void);

	std::map<std::string, double> loadDatabase(const std::string& file);

	class unopenedFileException : public std::exception {
		virtual const char *what() const throw();
	};
};
