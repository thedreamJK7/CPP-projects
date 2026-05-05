#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	std::cout << "(ScavTrap)Default constructor called!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const & name)
	: ClapTrap(name)
{
	std::cout << "(ScavTrap)Parametrised constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(ScavTrap const & src)
	: ClapTrap(src)
{
	std::cout << "(ScavTrap)Copy constructor called!" << std::endl;
}

// Assignment operator
ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "(ScavTrap)Destructor called!" << std::endl;
}

/*
Xulosa:
attackDamage → qanchalik zarar berishini bildiradi (o‘zgarmaydi)
energyPoints → har actionda kamayadi
hitPoints → damage olganda kamayadi, repairda oshadi
*/
void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0 || this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack\n";
		return;
	}
	else
	{
		this->_energyPoints--;
		std::cout	<< "ScavTrap " << this->_name 
					<< " attacks " << target 
					<< ", causing " << this->_attackDamage 
					<< " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
