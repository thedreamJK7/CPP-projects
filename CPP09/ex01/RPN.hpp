#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>
#include <exception>
#include <limits>

class RPN {
	public:
		RPN();
		~RPN();

		int	evaluate(const std::string &);

		class Error: public std::exception {
			virtual const char* what() const throw() {
				return "Error";
			}
		};
	
	private:
		RPN(const RPN &);
		RPN &operator = (const RPN &);
};

#endif
