#ifndef EX02_PMERGE_H
#define EX02_PMERGE_H

#include <iostream>
#include <vector>
#include <exception>
#include <sstream>

struct Pair {
	int	small;
	int	large;
};

class PmergeMeVector {
	public:
		PmergeMeVector(const char* argv[]);
		~PmergeMeVector();

		void	printArr() {
			for (std::vector<int>::iterator it = _mainChain.begin(); it != _mainChain.end(); it++) {
				std::cout << *it << std::endl;
			}
		};
		void	printPair() {
			for (std::vector<Pair>::iterator it = _pairs.begin(); it != _pairs.end(); it++) {
				std::cout << "(" << (*it).large << ", " << (*it).small << ")" << std::endl;
			}	
		}
		class Error: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			};
		};
		void				makePair();
		void				sortLarge();
		std::vector<Pair>	getPairs() { return _pairs;};
		void				buildMainChain();
		void				mergeInsertion();
		

	private:
		std::vector<int>	_nums;
		std::vector<Pair>	_pairs;
		std::vector<int>	_mainChain;
		std::vector<int>	_unsorted;
		int					_leftover;

		PmergeMeVector();
		PmergeMeVector(const PmergeMeVector&);
		PmergeMeVector &operator=(const PmergeMeVector&);
};

#endif