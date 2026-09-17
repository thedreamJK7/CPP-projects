#ifndef EX02_PMERGEVECTOR_H
#define EX02_PMERGEVECTOR_H

#include <iostream>
#include <vector>
#include <exception>
#include <sstream>
#include <ctime>

class PmergeMeVector {
	public:
		PmergeMeVector(const char* argv[]);
		~PmergeMeVector();

		typedef std::vector< std::pair<int, int> >				vecP;
		typedef std::vector<int> 								vec;
		typedef std::vector< std::pair<int, int> >::iterator	iteratorP;
		typedef std::vector<int>::iterator						iterator;
		typedef std::vector<int>::const_iterator				const_iterator;

		void	insertionSort();
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

	private:
		vec		_nums;
		vec		_mainChain;
		vecP	_pairs;
		int		_leftover;

		void	makePair();
		void	merge(iteratorP begin, iteratorP mid, iteratorP end);
		void	mergeSort(iteratorP begin, iteratorP end);
		void	binaryInsert();
		void	buildMainChain();

		PmergeMeVector();
		PmergeMeVector(const PmergeMeVector&);
		PmergeMeVector &operator=(const PmergeMeVector&);
};

#endif