#ifndef PMERMEDEQUE_HPP
#define PMERMEDEQUE_HPP

#include <deque>
#include <iostream>
#include <exception>
#include <sstream>

typedef std::deque< std::pair<int, int> >			deqP; //  alias for deque<pair> container
typedef std::deque<int> 							deq; //  alias for deque<pair> container
typedef std::deque< std::pair<int, int> >::iterator	iteratorP; // alias for deque<pair> iterator
typedef std::deque<int>::iterator					iterator; // alias for deque iterator
typedef std::deque<int>::const_iterator				const_iterator; // alias for const deque iterator

class PmergeMeDeque {
	public:
		PmergeMeDeque(const char* argv[]);
		~PmergeMeDeque();

		void	printBefore() const {
			for (const_iterator it = _nums.begin(); it != _nums.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		};
		void	printAfter() const {
			for (const_iterator it = _mainChain.begin(); it != _mainChain.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		};
		void	printPair() {
			for (iteratorP it = _pairs.begin(); it != _pairs.end(); it++) {
				std::cout << "(" << (*it).first << ", " << (*it).second << ")" << std::endl;
			}
		}
		class Error: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			};
		};

		void	insertionSort();
		void	makePair();
		void	merge(iteratorP begin, iteratorP mid, iteratorP end);
		void	mergeSort(iteratorP begin, iteratorP end);
		void	buildMainChain();
		

	private:
		deq		_nums;
		deq		_mainChain;
		deq		_unsorted;
		deqP	_pairs;
		int		_leftover;


		PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque&);
		PmergeMeDeque &operator=(const PmergeMeDeque&);
};

#endif