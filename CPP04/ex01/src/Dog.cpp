#include "../includes/Dog.hpp"

Dog::Dog(): Animal()
{
	_brain = new Brain();
	std::cout << "(Dog)Default constructor called" << std::endl;
}

Dog::Dog(std::string const & type): Animal(type)
{
	_brain = new Brain();
	std::cout << "(Dog)Parametrised constructor called" << std::endl;
}

Dog::Dog(Dog const & src): Animal(src)
{
	std::cout << "(Dog)Copy constructor called!" << std::endl;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "(Dog)Assignment operator called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "(Dog)Destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "WooowWoow!" << std::endl;
}

