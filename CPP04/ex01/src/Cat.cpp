#include "../includes/Cat.hpp"

Cat::Cat(): Animal()
{
	_brain = new Brain;
	std::cout << "(Cat)Default constructor called" << std::endl;
}

Cat::Cat(std::string const & type): Animal(type)
{
	_brain = new Brain;
	std::cout << "(Cat)Parametrised constructor called" << std::endl;
}

Cat::Cat(Cat const & src): Animal(src)
{
	std::cout << "(Cat)Copy constructor called!" << std::endl;
	_brain = new Brain(*src._brain);
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

