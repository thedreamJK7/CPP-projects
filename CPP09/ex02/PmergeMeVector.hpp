#ifndef EX02_PMERGEVECTOR_H
#define EX02_PMERGEVECTOR_H

#include <iostream>
#include <vector>
#include <exception>
#include <sstream>
#include <ctime>

struct Pair {
	int	small;
	int	large;
};

class PmergeMeVector {
	public:
		// orthodox canonical form
		PmergeMeVector(const char* argv[]);
		~PmergeMeVector();

		void	sort();
		class Error: public std::exception {
			virtual const char* what() const throw() {
				return ("Error");
			};
		};

		void	printBefore() const {
			for (std::vector<int>::const_iterator it = _nums.begin(); it != _nums.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		};
		void	printAfter() const {
			for (std::vector<int>::const_iterator it = _mainChain.begin(); it != _mainChain.end(); it++) {
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		};
		
	private:
		// Data
		std::vector<int>	_nums;
		std::vector<Pair>	_pairs;
		std::vector<int>	_mainChain;
		std::vector<int>	_unsorted;
		int					_leftover;

		// Sort steps
		void				makePair();
		void				sortPairsByLarge();
		void				buildMainChain();
		void				insertPending(int value);
		void				mergeInsertion();

		// Helpers
		int					findPartner(int	pendingVal) const;
		int					binarySearch(int target, int bound) const; 

		// Canonical form - blocked
		PmergeMeVector();
		PmergeMeVector(const PmergeMeVector&);
		PmergeMeVector &operator=(const PmergeMeVector&);
};

#endif