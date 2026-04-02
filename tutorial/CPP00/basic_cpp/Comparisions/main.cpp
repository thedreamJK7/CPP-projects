#include "example.hpp"
#include <iostream>

int main()
{
	example increment1(42);
	example	increment2(42);

	if (&increment1 == &increment1) // comparing the address of objects
		std::cout << "increment1 and increment1 are phsically equal" << std::endl;
	else
		std::cout << "increment1 and increment1 are phsically not equal" << std::endl;

	if (&increment1 == &increment2)
		std::cout << "increment1 and increment2 are phsically equal" << std::endl;
	else
		std::cout << "increment1 and increment2 are phsically not equal" << std::endl;
	
	if (increment1.compare(&increment1) == 0)		// comparing the value of the objects
		std::cout << "increment1 and increment1 are structurally equal" << std::endl;
	else
		std::cout << "increment1 and increment1 are structurally not equal" << std::endl;
	
	if (increment1.compare(&increment2) == 0)		// comparing the value of the objects
		std::cout << "increment1 and increment1 are structurally equal" << std::endl;
	else
		std::cout << "increment1 and increment1 are structurally not equal" << std::endl;
	return (0);
}
