#ifndef PMERMEDEQUE_HPP
#define PMERMEDEQUE_HPP

#include <deque>
#include <iostream>
#include <exception>
#include <sstream>

class PmergeMeDeque {
	public:
		PmergeMeDeque(const char* argv[]);
		~PmergeMeDeque();

		typedef std::deque< std::pair<int, int> >			deqP;
		typedef std::deque<int> 							deq;
		typedef std::deque< std::pair<int, int> >::iterator	iteratorPair;
		typedef std::deque<int>::iterator					iteratorD;
		typedef std::deque<int>::const_iterator				const_iteratorD;

		void	insertionSort();
		void	printBefore() const {
			for (const_iteratorD it = _nums.begin(); it != _nums.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		};
		void	printAfter() const {
			for (const_iteratorD it = _mainChain.begin(); it != _mainChain.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		};
		class Error: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			};
		};

	private:
		deq		_nums;
		deq		_mainChain;
		deqP	_pairs;
		int		_leftover;

		void	makePair();
		void	merge(iteratorPair begin, iteratorPair mid, iteratorPair end);
		void	mergeSort(iteratorPair begin, iteratorPair end);
		void	binaryInsert();
		void	buildMainChain();

		PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque&);
		PmergeMeDeque &operator=(const PmergeMeDeque&);
};

#endif