#include "Array.hpp"

int main(void)
{
	try
	{
		Array<int> p1(4);

		p1[0] = 1;
		p1[1] = 2;
		p1[2] = 3;
		p1[3] = 4;

		std::cout << p1[0] << std::endl;
		std::cout << p1.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
