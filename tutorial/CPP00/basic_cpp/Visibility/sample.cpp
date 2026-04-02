#include "sample.hpp"
#include <iostream>

sample::sample(void)
{
	std::cout << "Contsructer called" << std::endl;
	this->foo = 42;
	this->bar();
	return;
}

sample::~sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void sample::bar(void)
{
	std::cout << "Member function bar called" << std::endl;
	return;
}
