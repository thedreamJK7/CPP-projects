#include "example.hpp"
#include <iostream>

example::example(int value)
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

int	example::compare(example *other)
{
	if (this->_foo < other->getFoo())
		return (-1);
	else if (this->_foo > other->getFoo()) 
		return (1);
	return (0);
}
