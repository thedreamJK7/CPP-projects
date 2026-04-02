#include <iostream>

int main()
{
	int numberOfBalls = 42;

	int * ballsPtr = &numberOfBalls;
	// refering to the number of balls then we can call either numberoffballs or ballsref
	// and also we can declare ref without initializing; that is the disadvantage of ref
	int & ballsRef = numberOfBalls;

	std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl; 
	return (0);
}
