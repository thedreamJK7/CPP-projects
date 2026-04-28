#include "Zombie.hpp"

/*
newZombie, which creates a zombie on the heap and returns a pointer
*/
Zombie* newZombie(std::string name)
{
	Zombie *foo = new Zombie(name);

	return (foo);
}
