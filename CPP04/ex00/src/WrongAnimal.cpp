#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Generic")
{
	std::cout << "(WrongAnimal)Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string const & type): type(type)
{
	std::cout << "(WrongAnimal)Parametrised constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src): type(src.type)
{
	std::cout << "(WrongAnimal)Copy constructor called!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << "(WrongAnimal)Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "(WrongAnimal)Destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "(Generic)WrongAnimal makes sound!" << std::endl;
}

