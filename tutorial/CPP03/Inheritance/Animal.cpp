#include "Animal.hpp"

// Constructor
Animal::Animal(): _numOfLegs(4)
{
	std::cout << "Animal constructed" << std::endl;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructed" << std::endl;
}

// Copy constructor
Animal::Animal(Animal const & src)
{
	std::cout << "(Animal)Copy constructor called!" << std::endl;
	*this = src;
}


// Assignment operator
Animal &Animal::operator=(Animal const &src)
{
	std::cout << "(Animal)Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_numOfLegs = src._numOfLegs;
	}
	return (*this);
}

void	Animal::run(int	distance)
{
	std::cout << "Animal runs " << distance << " km/h" << std::endl;
}

void	Animal::call()
{
	std::cout << "Animal make a sound!" << std::endl;
}

void	Animal::eat(std::string const & what)
{
	std::cout << "Animal eats " << what << " per day!" << std::endl;
}

void	Animal::walk(int	distance)
{
	std::cout << "Animal walks " << distance << " meters/h" << std::endl;
}
