#include "Sorter.hpp"

Sorter::Sorter(void) {}

Sorter::Sorter(const Sorter& other) {}

Sorter& Sorter::operator=(const Sorter& other) {
	if (this != &other) {}
	return (*this);
}

Sorter::~Sorter(void) {}

std::vector<int> Sorter::sortVector(std::vector<int>& valuesVec) {

	std::vector<int> result;
	std::vector<int> smallValues;
	std::vector<int> bigValues;
	std::vector<int>::iterator pos;

	std::size_t pairsNb = 0;
	for (pos = valuesVec.begin(); pos != valuesVec.end(); ++pos) {

		int p1 = *pos;
		++pos;

		if (pos != valuesVec.end()) {
			++pairsNb;
			int p2 = *pos;

			bigValues.push_back(std::max(p1, p2));
			smallValues.push_back(std::min(p1, p2));
		} else {
			bigValues.push_back(p1);
		}
	}
	if (pairsNb > 0) {
		sortVector(bigValues);
	}
}
