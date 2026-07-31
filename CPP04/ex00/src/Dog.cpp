#include "../includes/Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "(Dog)Default constructor called" << std::endl;
}

Dog::Dog(Dog const & src): Animal(src)
{
	std::cout << "(Dog)Copy constructor called!" << std::endl;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "(Dog)Assignment operator called" << std::endl;
	if (this != &src)
		Animal::operator=(src);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "(Dog)Destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "WooowWoow!" << std::endl;
}

