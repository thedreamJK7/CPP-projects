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
		Parent *a = &child1; // implicit upcast

		//Parent *b = &child1; // implicit upcast -> ok
		Parent *b = static_cast<Parent *>(&child1); // explicit upcast
		//Child1 *c = b; // implicit downcast

		Child1 *d = static_cast<Child1 *>(b); // explicit downcast but no runtime check
		// Unrelated *e = static_cast<Unrelated *>(&child1);
	}
	return (0);
}
