#include "Zombie.hpp"

/*
randomChump, which creates a zombie on the stack and 
immediately makes it announce itself.
*/
void	randomChump(std::string name)
{
	Zombie foo = Zombie(name);

	foo.announce();
}
