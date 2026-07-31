#include "../includes/Animal.hpp"



Animal::Animal(): type("Generic")
{
	std::cout << "(Animal)Default constructor called" << std::endl;
}

Animal::Animal(std::string const & name): type(name)
{
	std::cout << "(Animal)Parametrised constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "(Animal)Copy constructor called!" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &src)
{
	std::cout << "(Animal)Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "(Animal)Destructor called" << std::endl;
}


