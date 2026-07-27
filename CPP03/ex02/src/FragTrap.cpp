#include "../includes/FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "(FragTrap)Default constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	this->_attackDamage = 30;
	std::cout << "(FragTrap)Parametrised constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << "(FragTrap)Copy constructor called!" << std::endl;
	*this = src;
}

// Assignment operator
FragTrap &FragTrap::operator=(FragTrap const &src)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_attackDamage = src._attackDamage;
		this->_energyPoints = src._energyPoints;
		this->_hitPoints = src._hitPoints;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "(FragTrap)Destructor called!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap can't ask for a high five because it's destroyed!" << std::endl;
		return;
	}
	std::cout << "FragTrap requests a high five! ✋" << std::endl;
}
