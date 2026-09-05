#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& rhs) { 
	(void)rhs;
}
RPN &RPN::operator = (const RPN& rhs) { 
	(void)rhs;
	return (*this);
}

static bool isOperand(std::string& c) {
	std::string operands = "+-/*";

	if (operands.find(c, 0) != std::string::npos) {
		return true;
	}
	return false;
}

static bool	isDigit(std::string& c) {
	if (c >= "0" && c <= "9") {
		return true;
	}
	return false;
}

int RPN::evaluate(std::string& str) {
	std::string			token;
	std::stringstream	ss(str);
	std::stack<int>		stored;
	
	while (ss >> token) {
		if (isOperand(token) && token.size() == 1) {
			if (stored.size() < 2) {
				std::cerr << "Error" << std::endl;
				return 1;
			}
			int a = stored.top();
			stored.pop();
			int b = stored.top();
			stored.pop();
		} else if (isDigit(token) && token.size() == 1) {
			stored.push(std::atoi(token.c_str()));
		} else {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}
	return (0);
}