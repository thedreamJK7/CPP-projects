#include "sample1.hpp"
#include <iostream>

int main()
{
	sample1 instance('s', 42, 42.42);

	std::cout << "a1 = " << instance.a1 << std::endl;
	std::cout << "a2 = " << instance.a2 << std::endl;
	std::cout << "a3 = " << instance.a3 << std::endl;
	return (0);
}
