#include <exception>
#include <iostream>
#include <typeinfo>

class Parent {
	public:
		virtual ~Parent(){};
};

class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated {};

int main( void )
{
	Child1 a;

	Parent *b = &a; // implicit upcast

	Child1 *c = dynamic_cast<Child1 *>(b);
	if (!c)
		std::cout << "Bad casting!" << std::endl;
	else
		std::cout << "Good casting casting!" << std::endl;
	
	try
	{
		Child2 *d = dynamic_cast<Child2 *>(b);
		if (!d)
			std::cout << "Good boy!" << std::endl;
	}
	catch(std::bad_cast &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
