#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "(WrongCat)Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string const & type): WrongAnimal(type)
{
	std::cout << "(WrongCat)Parametrised constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src): WrongAnimal(src)
{
	std::cout << "(WrongCat)Copy constructor called!" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	std::cout << "(WrongCat)Assignment operator called" << std::endl;
	if (this != &src)
		WrongAnimal::operator=(src);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "(WrongCat)Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meooww!" << std::endl;
}
