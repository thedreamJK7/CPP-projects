#include "const.hpp"
#include <iostream>

example::example(float const fi) : pi(fi), q(42) // we must initialize the value of objects always constructor + initialization
{
	std::cout << "Contsructer called" << std::endl;
};


example::~example()
{
	std::cout << "Destructor called" << std::endl;
};

void	example::bar(void) const
{
	std::cout << "This->pi = " << this->pi << std::endl;
	std::cout << "This->q = " << this->q << std::endl;

	return;
}
