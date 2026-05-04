#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("Generic"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "(ClapTrap)Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string const & name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "(ClapTrap)Parametrised constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "(ClapTrap)Copy constructor called!" << std::endl;
	*this = src;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(ClapTrap const &src)
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

ClapTrap::~ClapTrap()
{
	std::cout << "(ClapTrap)Destructor called!" << std::endl;
}

/*
Xulosa:
attackDamage → qanchalik zarar berishini bildiradi (o‘zgarmaydi)
energyPoints → har actionda kamayadi
hitPoints → damage olganda kamayadi, repairda oshadi
*/
void ClapTrap::attack(const std::string& target)
{
	if (!(this->_hitPoints && this->_energyPoints))
	{
		std::cout << "ClapTrap " << this->_name << " can't attack\n";
		return;
	}
	else
	{
    this->_energyPoints--;
	std::cout	<< "ClapTrap " << this->_name 
				<< " attacks " << target 
				<< ", causing " << this->_attackDamage 
				<< " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " dead!" << std::endl;
	}
	else
	{
		std::cout	<< "ClapTrap " << this->_name << " takes " 
					<< amount << " damage!"
					<< std::endl;
		if (this->_hitPoints > amount)
		{
			this->_hitPoints -= amount;
		}
		else
		{
			this->_hitPoints = 0;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!(this->_energyPoints && this->_energyPoints))
	{
		std::cout << "ClapTrap " << this->_name << " can't be repaired!" << std::endl;
	}
	else
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}
