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

		class Error: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			};
		};

	private:
		std::deque<int>						_nums;
		std::deque< std::pair<int, int> >	_pairs;
		int				_leftover;


		PmergeMeDeque();
		PmergeMeDeque(const PmergeMeDeque&);
		PmergeMeDeque &operator=(const PmergeMeDeque&);
};

#endif