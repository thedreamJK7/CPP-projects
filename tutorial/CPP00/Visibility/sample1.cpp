#include "sample1.hpp"
#include <iostream>

sample1::sample1(char p1, int p2, float p3)
{
	std::cout << "Contsructer called" << std::endl;
	this->a1 = p1;
	this->a2 = p2;
	this->a3 = p3;

	return;
}

sample1::~sample1(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
