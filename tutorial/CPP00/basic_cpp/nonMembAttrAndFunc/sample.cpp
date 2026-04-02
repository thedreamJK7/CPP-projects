#include "sample.hpp"
#include <iostream>

sample::sample()
{
	std::cout << "Contsructer called" << std::endl;
	sample::_mbInst += 1;
}

sample::~sample()
{
	std::cout << "Destructor called" << std::endl;
	sample::_mbInst -= 1;
}

int sample::getMbInst()
{
	return (sample::_mbInst);
}

int sample::_mbInst = 0;
