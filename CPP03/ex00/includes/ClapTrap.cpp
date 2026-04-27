#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string const & name): _name(name)
{
	std::cout << "Parametrised constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = src;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &src)
	{
		
	}
	return (*this);
}


void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}