#include "Pair.class.tpp"

int main( void )
{
	std::cout << "Primary template" << std::endl;
	{
		Pair<std::string, int> p1(std::string("hello"), 42);

		std::cout << p1 << std::endl;
	}
	std::cout << "Specialized int template" << std::endl;
	{
		Pair<int, float> p1(42, 42.24f);

		std::cout << p1 << std::endl;	
	}
	std::cout << "Specialized bool template" << std::endl;
	{
		Pair<bool, bool> p1(true, true);

		std::cout << p1 << std::endl;
	}
	return (0);
}