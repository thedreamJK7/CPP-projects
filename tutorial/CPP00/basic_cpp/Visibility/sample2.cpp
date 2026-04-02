#include "sample2.hpp"
#include <iostream>

sample2::sample2(char p1, int p2, float p3): a1(p1), a2(p2), a3(p3)
{
	std::cout << "Contsructer called" << std::endl;
	std::cout << "This->a1 = " << this->a1 << std::endl;
	std::cout << "This->a2 = " << this->a2 << std::endl;
	std::cout << "This->a3 = " << this->a3 << std::endl;

	return;
}

sample2::~sample2(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
