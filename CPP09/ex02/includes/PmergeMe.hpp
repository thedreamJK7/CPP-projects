#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <deque>
#include "jacobSequence.hpp"

template <typename Container> class PmergeMe {
	public:
		PmergeMe(const char* argv[]);
		~PmergeMe();

		typedef	Container							cont;
		typedef typename	cont::iterator			iterator;
		typedef typename	cont::const_iterator	const_iterator;
		typedef	std::pair<int, int>					Pair;
		typedef	std::vector<Pair>					PairVec;
		typedef	PairVec::iterator					PairVecIt;

		void	insertionSort();
		void	printBefore() const;
		void	printAfter() const;

		class Error: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			};
		};

	private:
		cont		_nums;
		cont		_mainChain;
		PairVec		_pairs;
		int			_leftover;

		void		makePair();
		void		merge(PairVecIt begin, PairVecIt mid, PairVecIt end);
		void		mergeSort(PairVecIt begin, PairVecIt end);
		void		binaryInsert();
		void		buildMainChain();

		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe &operator=(const PmergeMe&);
};

#include "PmergeMeConsDes.tpp"
#include "PmergeMe.tpp"
#include "PmergeMePrint.tpp"

#endif