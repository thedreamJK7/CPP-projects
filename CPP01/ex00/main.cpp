#include "Zombie.hpp"

int main()
{
	Zombie *zombie;

	zombie = newZombie("Foo1");
	zombie->announce();
	randomChump("Foo2");
	delete zombie;
	return (0);
}
