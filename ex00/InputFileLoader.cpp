#include "InputFileLoader.hpp"

InputFileLoader::InputFileLoader(IParser& parser) : _parser(parser) {}

InputFileLoader::InputFileLoader(const InputFileLoader& other) : _parser(other._parser) {}

InputFileLoader& InputFileLoader::operator=(const InputFileLoader& other) {
	if (this != &other) {
		this->_parser = other._parser;
	}
	return (*this);
}

void InputFileLoader::trimSpaces(std::string& str) {

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

InputFileLoader::~InputFileLoader(void) {}

std::map<std::string, double> InputFileLoader::loadInput(const std::string& file) {

	std::map<std::string, double> inputContent;

	std::ifstream fileStream(file.c_str());
	if (!fileStream.is_open()) {
		throw unopenedFileException();
	}

	std::string currLine;
	while (std::getline(fileStream, currLine)) {

		if (currLine.empty())
			continue;

		std::stringstream ss(currLine);
		std::string date;
		std::string valueStr;

		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {

			trimSpaces(date);
			trimSpaces(valueStr);
			if (!_parser.isValidDate(date) || !_parser.isValidValue(valueStr)) {
				std::cerr << "Invalid line in input ignored => " << currLine << std::endl;
			} else {

				double value = std::strtod(valueStr.c_str(), NULL);
				std::pair<std::map<std::string,double>::iterator, bool> res;
				res = inputContent.insert(std::make_pair(date, value));

				if (!res.second) {
					std::cerr << "Warning: duplicate date in input file ignored => " << date << std::endl;
				}
			}
		}
	}
	return (inputContent);
}

// EXCEPTIONS

const char *InputFileLoader::unopenedFileException::what() const throw() {
	return ("Error: cannot open input file");
}

// TRIM ESPACES

// OPERATEUR DE COPIE ET D'ASSIGN EN PRIVATE

// QUESTION DES DOUBLONS ICI
