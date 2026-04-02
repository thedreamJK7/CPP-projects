#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie foo = Zombie(name);

	foo.announce();
}
