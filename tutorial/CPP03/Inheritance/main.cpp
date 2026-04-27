#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "Test1, creating the animal object" << std::endl;
		Animal anim;

		anim.eat("Meat");
		anim.run(20);
	}

	{
		std::cout << "Test2, creating the cat object" << std::endl;
		Cat meowmeow;

		std::cout << "Test2, calling the inherited methods " << std::endl;
		meowmeow.eat("Elephant");
		meowmeow.run(25);

		std::cout << "Test2, Calling cat specified methods" << std::endl;
		meowmeow.scornTarget("Dog");
	}


	{
		std::cout << "Test3, creating an original object" << std::endl;
		Cat original;

		std::cout << "Test3, calling the copy constructor" << std::endl;
		Cat meowmeow(original);

		std::cout << "Test3, calling the assignmend operator" << std::endl;
		Cat assigned;
		assigned = original;

		std::cout << "All the objects are destructing!" << std::endl;
	}
	return 0;
}
