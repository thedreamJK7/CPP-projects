#ifndef PMERGEMEPRINT_T
#define PMERGEMEPRINT_T

#include "PmergeMe.hpp"

template <typename Container>
void	PmergeMe<Container>::printBefore() const {
	for (const_iterator it = _nums.begin(); it != _nums.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};
template <typename Container>
void	PmergeMe<Container>::printAfter() const {
	for (const_iterator it = _mainChain.begin(); it != _mainChain.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
};

#endif
