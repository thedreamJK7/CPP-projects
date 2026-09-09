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

		void print() {
			for (std::vector<int>::iterator it = _nums.begin(); it != _nums.end(); it++) {
				std::cout << *it << std::endl;
			}
		};
		class Error: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			};
		};
		std::vector<Pair> makePair(void);

	private:
		std::vector<int>	_nums;

		PmergeMeVector();
		PmergeMeVector(const PmergeMeVector&);
		PmergeMeVector &operator=(const PmergeMeVector&);
};

#endif