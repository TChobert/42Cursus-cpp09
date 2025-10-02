#include "DatabaseLoader.hpp"

DatabaseLoader::DatabaseLoader(void) {}

DatabaseLoader::DatabaseLoader(const DatabaseLoader& other){}

DatabaseLoader::~DatabaseLoader(void) {}

DatabaseLoader& DatabaseLoader::operator=(const DatabaseLoader& other) {
	if (this != &other) {
		return (*this);
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
			double value = std::strtod(valueStr.c_str(), NULL);
			DBcontent[date] = value;
		}
	}
	return (DBcontent);
}

/// EXCEPTIONS

const char *DatabaseLoader::unopenedFileException::what() const throw() {
	return ("Error: cannot open data base file");
}
