#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "(Brain)Default constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];	
	std::cout << "(Brain)Copy constructor called!" << std::endl;
}

Brain &Brain::operator=(Brain const &src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	std::cout << "(Brain)Assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "(Brain)Destructor called" << std::endl;
}
