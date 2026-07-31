#include "../includes/Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "(Cat)Default constructor called" << std::endl;
}

Cat::Cat(Cat const & src): Animal(src)
{
	std::cout << "(Cat)Copy constructor called!" << std::endl;
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "(Cat)Assignment operator called" << std::endl;
	if (this != &src)
		Animal::operator=(src);
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

