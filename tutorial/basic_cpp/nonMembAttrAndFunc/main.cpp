#include "sample.hpp"
#include <iostream>

int main()
{
	sample obj1;
	sample obj2;

	std::cout << "How many times called: " << obj2.getMbInst() << std::endl;
	return (0);
}
