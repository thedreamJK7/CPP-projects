#include "Cat.hpp"

// Constructor
// Its not necessary to call the parent constructor because it is automatically called by itself
// Its just a good practice
Cat::Cat(): Animal()
{
	std::cout << "Cat constructed" << std::endl;
}

// Destructor
// In C++, the derived destructor runs first, and then the base class destructor
// is called automatically. A virtual base destructor matters when deleting
// derived objects through base-class pointers.
Cat::~Cat()
{
	std::cout << "Cat destructed" << std::endl;
}

// Copy constructor
Cat::Cat(Cat const & src): Animal(src)
{
	std::cout << "(Cat)Copy constructor called!" << std::endl;
	// Here we would copy additional variables from Cat if there were any.
	// *this = src; // Not necessary, since Animal(src) has already handled the base part.
}

// Assignment operator
Cat &Cat::operator=(Cat const &src)
{
	std::cout << "(Cat)Assignment operator called" << std::endl;
	if (this != &src)
	{
		// IMPORTANT: Copy the Animal part first!
		Animal::operator=(src);

		// Afterwards, copy Cat-specific variables here (if present)
	}
	return (*this);
}

void Cat::scornTarget(std::string	const & target)
{
	std::cout << "Hshshshshshsh " << target << std::endl;
}
