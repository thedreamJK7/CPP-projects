#include "Zombie.hpp"

int main()
{
	Zombie *Zombie;

	Zombie = newZombie("Foo1");
	Zombie->announce();
	randomChump("Foo2");
	delete Zombie;
	return (0);
}
