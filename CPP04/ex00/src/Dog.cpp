#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "(Dog)Default constructor called" << std::endl;
}

Dog::Dog(std::string const & type): Animal(type)
{
	std::cout << "(Dog)Parametrised constructor called" << std::endl;
}

Dog::Dog(Dog const & src): Animal(src)
{
	std::cout << "(Dog)Copy constructor called!" << std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "(Dog)Assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
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

