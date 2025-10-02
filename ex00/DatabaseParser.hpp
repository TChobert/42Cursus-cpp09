#pragma once

#include <map>
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>

class DatabaseParser {

	public:

	DatabaseParser(void);
	DatabaseParser(const DatabaseParser& other);
	~DatabaseParser(void);
	DatabaseParser& operator=(const DatabaseParser& other);

	void parse(std::map<std::string, double>& DBcontent);
};
