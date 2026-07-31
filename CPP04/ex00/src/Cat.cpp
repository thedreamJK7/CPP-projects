#include "../includes/Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "(Cat)Default constructor called" << std::endl;
}

Cat::Cat(std::string const & type): Animal(type)
{
	std::cout << "(Cat)Parametrised constructor called" << std::endl;
}

Cat::Cat(Cat const & src): Animal(src)
{
	std::cout << "(Cat)Copy constructor called!" << std::endl;
	*this = src;
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "(Cat)Assignment operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "(Cat)Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meooww!" << std::endl;
}

