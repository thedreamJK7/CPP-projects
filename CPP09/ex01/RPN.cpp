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

	if (c.size() == 1 && operands.find(c, 0) != std::string::npos) {
		return true;
	}
	return false;
}

static int executeOperand(std::string& token, int &a, int& b) {
	double	res;
	if (token == "+")
		res = a + b;
	else if (token == "-")
		res = b - a;
	else if (token == "*" )
		res = b * a;
	else if (token == "/") {
		if (a == 0)
			throw RPN::Error();
		res = b / a;
	}
	if (res > std::numeric_limits<int>::max() 
		|| res < std::numeric_limits<int>::min()) {
		throw RPN::Error();
	}
	return static_cast<int>(res);
}

static bool	isDigit(std::string& c) {
	if (c.size() == 1 && c >= "0" && c <= "9") {
		return true;
	}
	return false;
}

int RPN::evaluate(const std::string& str) {
	std::string			token;
	std::stringstream	ss(str);
	std::stack<int>		stored;

	while (ss >> token) {
		if (isOperand(token)) {
			if (stored.size() < 2) {
				throw RPN::Error();
			}
			int a = stored.top();
			stored.pop();
			int b = stored.top();
			stored.pop();
			try {
				int res = executeOperand(token, a, b);
				stored.push(res);
			} catch(const std::exception& e) {
				throw ;
			}
		} else if (isDigit(token)) {
			stored.push(std::atoi(token.c_str()));
		} else {
			throw RPN::Error();
		}
	}
	if (stored.size() > 1 || stored.empty())
		throw RPN::Error();
	return (stored.top());
}