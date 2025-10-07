#include "PMergeme.hpp"

PMergeme::PMergeme(void) {}

PMergeme::PMergeme(const PMergeme& other) {
	(void)other;
}

PMergeme& PMergeme::operator=(const PMergeme& other) {
	if (this != &other) {}
	return (*this);
}

PMergeme::~PMergeme(void) {}

bool PMergeme::parseInput(int argsNb, char **args, std::vector<int>& numbers) {

	std::set<int> seen;

	for (int i = 0; i < argsNb; ++i) {

		char* end;
		long val = std::strtol(args[i], &end, 10);

		if (*end != '\0' || val < 0 || val > std::numeric_limits<int>::max()) {
			std::cerr << "Error" << std::endl;
			return (false);
		}

		if (!seen.insert(static_cast<int>(val)).second) {
			std::cerr << "Error" << std::endl;
			return (false);
		}

		numbers.push_back(static_cast<int>(val));
	}

	return (true);
}

std::vector<size_t> PMergeme::generateJacobsthalOrderVector(size_t size)
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

std::deque<size_t> PMergeme::generateJacobsthalOrderDeque(size_t size)
{
	std::deque<size_t> sequence;
	std::deque<size_t> order;
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

std::vector<int> PMergeme::sortVector(std::vector<int>& valuesVec) {

	std::cout << std::endl;
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

	std::vector<size_t> order = generateJacobsthalOrderVector(pendingValues.size());
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

std::deque<int> PMergeme::sortDeque(std::deque<int>& valuesDeq) {

	std::cout << std::endl;
	std::cout << "sortDeque called with: ";
	for (size_t i = 0; i < valuesDeq.size(); ++i)
		std::cout << valuesDeq[i] << " ";
	std::cout << std::endl;

	if (valuesDeq.size() <= 1) {
		std::cout << "Base case reached with size " << valuesDeq.size() << std::endl;
		return valuesDeq;
	}

	std::deque<int> mainChain;
	std::deque<int> pendingValues;
	std::deque<int> result;
	std::size_t pairsNb = 0;

	std::deque<int>::iterator pos = valuesDeq.begin();
	while (pos != valuesDeq.end())
	{
		int p1 = *pos;
		++pos;

		if (pos != valuesDeq.end())
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
		mainChain = sortDeque(mainChain);
		std::cout << "mainChain after recursion: ";
		for (size_t i = 0; i < mainChain.size(); ++i)
			std::cout << mainChain[i] << " ";
		std::cout << std::endl;
	}

	result = mainChain;

	std::deque<size_t> order = generateJacobsthalOrderDeque(pendingValues.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		if (idx >= pendingValues.size())
			continue;

		int value = pendingValues[idx];
		std::deque<int>::iterator insertPos =
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
