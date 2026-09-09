#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(const char* argv[]) {
	int	num;

	while (*argv != NULL) {
		std::stringstream ss(*argv);
		ss >> num;

		if (ss.fail() || !ss.eof() || num <= 0)
			throw Error();
		_nums.push_back(num);
		argv++;
	}
}

PmergeMeVector::~PmergeMeVector() { };

std::vector<Pair> PmergeMeVector::makePair(void) {
	std::vector<Pair> pairs;

	
}