#include <iostream>

class Parent {};

class Child1: public Parent {};
class Child2: public Parent {};

class Unrelated {};

int main( void )
{
	{
		int	a = 42;
		double b = a;	// implicit promotion
		int	d = static_cast<int>(b);

		std::cout << d << std::endl;
	}

	{
		Child1 child1;

		Parent *b = &child1; // implicit upcast -> ok
		//Child1 *c = b; // implicit downcast

		Child2 *d = static_cast<Child2 *>(b); // explicit downcast but no runtime check
		
	}
	return (0);
}
