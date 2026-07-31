#include "../includes/Cat.hpp"

Cat::Cat(): Animal("Cat"), _brain(new Brain())
{
	std::cout << "(Cat)Default constructor called" << std::endl;
}

Cat::Cat(Cat const & src): Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "(Cat)Copy constructor called!" << std::endl;
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "(Cat)Assignment operator called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		delete this->_brain;
		_brain = new Brain(*src._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "(Cat)Destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meooww!" << std::endl;
}

