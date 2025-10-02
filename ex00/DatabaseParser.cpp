#include "DatabaseParser.hpp"

DatabaseParser::DatabaseParser(void) {}

DatabaseParser::DatabaseParser(const DatabaseParser& other) {}

DatabaseParser::~DatabaseParser(void) {}

DatabaseParser& DatabaseParser::operator=(const DatabaseParser &other) {
	if (this != &other) {
		return (*this);
	}
}

void DatabaseParser::parse(std::map<std::string, double>& content) {
	
}