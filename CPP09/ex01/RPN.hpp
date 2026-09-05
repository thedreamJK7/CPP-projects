#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN {
	public:
		RPN();
		~RPN();
		int	evaluate(std::string &);
	
	private:
		RPN(const RPN &);
		RPN &operator = (const RPN &);
};

#endif
