#include "Sorter.hpp"

Sorter::Sorter(void) {}

Sorter::Sorter(const Sorter& other) {
	(void)other;
}

Sorter& Sorter::operator=(const Sorter& other) {
	if (this != &other) {}
	return (*this);
}

Sorter::~Sorter(void) {}

std::vector<size_t> Sorter::generateJacobsthalOrder(size_t size)
{
	std::vector<size_t> sequence;
	std::vector<size_t> order;
	size_t j0 = 0;
	size_t j1 = 1;

	// Générer les nombres de Jacobsthal <= size (éviter doublons)
	while (j1 <= size)
	{
		if (j1 > 0 && std::find(sequence.begin(), sequence.end(), j1) == sequence.end())
			sequence.push_back(j1);
		size_t next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}

	// Convertir J(k) (1-based) en indices 0-based et marquer visités
	std::vector<int> visited(size, 0);
	for (size_t i = 0; i < sequence.size(); ++i)
	{
		size_t idx = sequence[i] - 1;
		if (idx < size && !visited[idx])
		{
			order.push_back(idx);
			visited[idx] = 1;
		}
	}

	// Compléter avec les indices manquants
	for (size_t i = 0; i < size; ++i)
	{
		if (!visited[i])
			order.push_back(i);
	}

	std::cout << "Jacobsthal order for size " << size << " : ";
	for (size_t i = 0; i < order.size(); ++i)
		std::cout << order[i] << " ";
	std::cout << std::endl;

	return order;
}

std::vector<int> Sorter::sortVector(std::vector<int>& valuesVec) {

	std::cout << "sortVector called with: ";
	for (size_t i = 0; i < valuesVec.size(); ++i)
		std::cout << valuesVec[i] << " ";
	std::cout << std::endl;

	if (valuesVec.size() <= 1) {
		std::cout << "Base case reached with size " << valuesVec.size() << std::endl;
		return valuesVec;
	}

	std::vector<int> mainChain;
	std::vector<int> pendingValues;
	std::vector<int> result;
	std::size_t pairsNb = 0;

	std::vector<int>::iterator pos = valuesVec.begin();
	while (pos != valuesVec.end())
	{
		int p1 = *pos;
		++pos;

		if (pos != valuesVec.end())
		{
			int p2 = *pos;
			++pairsNb;

			mainChain.push_back(std::max(p1, p2));
			pendingValues.push_back(std::min(p1, p2));
			++pos;
		}
		else
		{
			pendingValues.push_back(p1);
		}
	}

	std::cout << "Pairs separated: mainChain = ";
	for (size_t i = 0; i < mainChain.size(); ++i)
		std::cout << mainChain[i] << " ";
	std::cout << ", pendingValues = ";
	for (size_t i = 0; i < pendingValues.size(); ++i)
		std::cout << pendingValues[i] << " ";
	std::cout << std::endl;

	if (pairsNb > 0) {
		std::cout << "Recursively sorting mainChain..." << std::endl;
		mainChain = sortVector(mainChain);
		std::cout << "mainChain after recursion: ";
		for (size_t i = 0; i < mainChain.size(); ++i)
			std::cout << mainChain[i] << " ";
		std::cout << std::endl;
	}

	result = mainChain;

	std::vector<size_t> order = generateJacobsthalOrder(pendingValues.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		if (idx >= pendingValues.size())
			continue;

		int value = pendingValues[idx];
		std::vector<int>::iterator insertPos =
			std::lower_bound(result.begin(), result.end(), value);
		result.insert(insertPos, value);
		std::cout << "Inserting pendingValues[" << idx << "] = " << value << " -> result = ";
		for (size_t j = 0; j < result.size(); ++j)
			std::cout << result[j] << " ";
		std::cout << std::endl;
	}

	std::cout << "Returning result: ";
	for (size_t i = 0; i < result.size(); ++i)
		std::cout << result[i] << " ";
	std::cout << std::endl << std::endl;

	return result;
}
