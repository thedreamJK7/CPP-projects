#ifndef PMERGEMECONSDES_TPP
#define PMERGEMECONSDES_TPP

#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe(const char* argv[]): _leftover(-1) {
	int	num;

	while (*argv != NULL) {
		std::stringstream ss(*argv);
		ss >> num;

		if (ss.fail() || !ss.eof() || num < 0)
			throw Error();
		_nums.push_back(num);
		argv++;
	}
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() { };

#endif