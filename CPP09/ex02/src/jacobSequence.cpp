#include "../includes/jacobSequence.hpp"

std::vector<int> jacobsthalSeq(std::size_t pendingSize) {
	std::vector<int> out;
	std::vector<int> jacob;
	if (pendingSize == 0) return out;
	
	// Copy terms < pendingSize
	for (std::size_t i = 0; i < 12; i++) {
		if (JACOBSTHAL[i] >= static_cast<int>(pendingSize)) break;
		jacob.push_back(JACOBSTHAL[i]);
	}

	// expanding each into descending runs + tail
	std::size_t last = 1;
	for (std::size_t i = 0; i < jacob.size(); i++)
	{
		out.push_back(jacob[i]);
		for (std::size_t j = jacob[i] - 1; last < j; --j)
			out.push_back(j);
		last = jacob[i];
	}
	for (std::size_t j = pendingSize; j > last; j--)
		out.push_back(j);
	return (out);
}
