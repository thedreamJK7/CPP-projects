#include "Base.hpp"
#include "ABC.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	int rand = std::rand() % 3 + 1;

	std:: cout << "rand = " << rand << std::endl;
	if (rand == 1)
	{
		std::cout << "A is generated" << std::endl;
		return (new A());
	}
	if (rand == 2)
	{
		std::cout << "B is generated" << std::endl;
		return (new B());
	}
	if (rand == 3)
	{
		std::cout << "C is generated" << std::endl;
		return (new C());
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A is identified with pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B is identified with pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C is identified with pointer" << std::endl;
	else
		std::cerr << "Error: Invalid type!" << std::endl;  
}

// reference cannot be null
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A is identified with reference" << std::endl;
		return ;
	}
	catch(const std::exception& e) { }
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B is identified with reference" << std::endl;
		return ;
	}
	catch(const std::exception& e) { }
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C is identified with reference" << std::endl;
		return ;
	}
	catch(const std::exception& e) { }
	std::cerr << "Error: Invalid type!" << std::endl;
}

int main( void )
{
	std::srand(time(NULL));
	Base *test;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "\nObject " << i << std::endl;
		test = generate();
		identify(test);
		identify(*test);
		delete test;
	}
	return 0;
}
