#include "example.hpp"
#include <iostream>

int main()
{
	example increment;

	std::cout << "initial value " << increment.getFoo() << std::endl;
	increment.setFoo(84);
	std::cout << "incremented value " << increment.getFoo() << std::endl;
	return (0);
}
