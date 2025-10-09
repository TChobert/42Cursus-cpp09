#include "InputFileLoader.hpp"

InputFileLoader::InputFileLoader(IParser& parser) : _parser(parser) {}

InputFileLoader& InputFileLoader::operator=(const InputFileLoader& other) {
	if (this != &other) {}
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

		size_t sepPos = currLine.find('|');
		if (sepPos == std::string::npos) {
			std::cerr << "Invalid line in input ignored => " << currLine << std::endl;
			continue;
		}

		if (currLine.find("date") != std::string::npos) {
			trimSpaces(currLine);
			if (currLine == "date | value")
				continue;
			else {
				std::cerr << "Invalid line in input ignored => " << currLine << std::endl;
				continue;
			}
		}

		std::string date = currLine.substr(0, sepPos);
		std::string valueStr = currLine.substr(sepPos + 1);

		trimSpaces(date);
		trimSpaces(valueStr);

		if (!_parser.isValidDate(date) || !_parser.isValidValue(valueStr)) {
			std::cerr << "Invalid line in input ignored => " << currLine << std::endl;
			continue;
		}

		double value = std::strtod(valueStr.c_str(), NULL);
		std::pair<std::map<std::string,double>::iterator, bool> res;
		res = inputContent.insert(std::make_pair(date, value));

		if (!res.second) {
			std::cerr << "Warning: duplicate date in input file ignored => " << date << std::endl;
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
