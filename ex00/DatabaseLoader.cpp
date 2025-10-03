#include "DatabaseLoader.hpp"

DatabaseLoader::DatabaseLoader(IParser& DBparser) : _DBparser(DBparser) {}

DatabaseLoader::DatabaseLoader(const DatabaseLoader& other) : _DBparser(other._DBparser) {}

DatabaseLoader::~DatabaseLoader(void) {}

DatabaseLoader& DatabaseLoader::operator=(const DatabaseLoader& other) {
	if (this != &other) {
		this->_DBparser = other._DBparser;
	}
	return (*this);
}

void DatabaseLoader::trimSpaces(std::string& str) {

	if (str.empty())
		return;

	size_t begin = str.find_first_not_of(' ');
	size_t end   = str.find_last_not_of(' ');

	if (begin == std::string::npos) {
		str.clear();
	} else {
		str = str.substr(begin, end - begin + 1);
	}
}

std::map<std::string, double> DatabaseLoader::loadDatabase(const std::string& file) {

	std::map<std::string, double> DBcontent;

	std::ifstream fileStream(file.c_str());
	if (!fileStream.is_open()) {
		throw unopenedFileException();
	}

	std::string headerLine;
	std::getline(fileStream,headerLine);

	std::string currLine;
	while (std::getline(fileStream, currLine)) {

		if (currLine.empty())
			continue;

		std::stringstream ss(currLine);
		std::string date;
		std::string valueStr;

		if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {

			trimSpaces(date);
			trimSpaces(valueStr);
			if (!_DBparser.isValidDate(date) || !_DBparser.isValidValue(valueStr)) {
				std::cerr << "Invalid line in DataBase ignored => " << currLine << std::endl; 
			} else {

				double value = std::strtod(valueStr.c_str(), NULL);
				std::pair<std::map<std::string,double>::iterator, bool> res;
				res = DBcontent.insert(std::make_pair(date, value));

				if (!res.second) {
					std::cerr << "Warning: duplicate date in DataBase ignored => " << date << std::endl;
				}
			}
		}
	}
	return (DBcontent);
}

/// EXCEPTIONS

const char *DatabaseLoader::unopenedFileException::what() const throw() {
	return ("Error: cannot open data base file");
}
