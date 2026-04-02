#include "example.hpp"
#include <iostream>

example::example()
{
	std::cout << "Contsructer " << std::endl;
	this->_foo = 42;
};

example::~example()
{
	std::cout << "Destructor " << std::endl;
};

int example::getFoo() const {
	return(this->_foo);
};

void example::setFoo(int newV) {
	if (newV >= 0)
		this->_foo = newV;
};
