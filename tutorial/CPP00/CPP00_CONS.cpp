#include <iostream>

class Klass
{
	int a;
	public:
		Klass() {std::cout << "Hi, 42!";} // Constructor
};

int main()
{
	Klass obj;
	return (0);
}
