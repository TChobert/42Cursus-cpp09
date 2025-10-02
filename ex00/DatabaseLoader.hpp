#pragma once

#include <iostream>
#include <map>
#include <cstdlib>
#include <exception>
#include <string>
#include <fstream>
#include <sstream>


class DatabaseLoader {

	public:

	DatabaseLoader(void);
	DatabaseLoader(const DatabaseLoader& other);
	DatabaseLoader& operator=(const DatabaseLoader& other);
	~DatabaseLoader(void);

	std::map<std::string, double> loadDatabase(const std::string& file);

	class unopenedFileException : public std::exception {
		virtual const char *what() const throw();
	};
};
