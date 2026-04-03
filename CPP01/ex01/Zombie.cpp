#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(const std::string &name): _name(name)
{
	
};

Zombie::~Zombie()
{
	
};

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
