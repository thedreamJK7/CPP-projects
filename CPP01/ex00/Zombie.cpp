#include "Zombie.hpp"

/*
and destructor to track when object is destroyed
*/
Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " is destroyed" << std::endl;
};

/*
Constructor for initializing the zombie with a name
*/
Zombie::Zombie(const std::string &name): _name(name)
{
	std::cout << "Zombie " << _name << " is created" << std::endl;
};

/*
the announce allows each zombie to print its message
*/
void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

