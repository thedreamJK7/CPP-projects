#include "iter.hpp"

int main( void )
{
	int		num[] = {1, 2, 3, 4, 5};
	int const		numC[] = {1, 2, 3, 4, 5};
	double	dNum[] = {0, 1, 2, 3};
	char	cArr[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "Printing integer array!" << std::endl;
	printArr(num, 5);
	iter(num, 5, add<int>);
	printArr(num, 5);

	std::cout << "\nPrinting double array!" << std::endl;
	printArr(dNum, 4);
	//iter(dNum, 4, add<double>);
	//printArr(dNum, 4);

	std::cout << "\nPrinting char array!" << std::endl;
	printArr(cArr, 5);
	iter(cArr, 5, add<char>);
	printArr(cArr, 5);

	std::cout << "\nPrinting const int array!" << std::endl;
	printArr(numC, 5);
	iter(numC, 5, print<int>);
	return (0);
}
