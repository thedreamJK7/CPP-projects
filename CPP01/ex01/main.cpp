#include "Zombie.hpp"

/*
In this ex, the goal is to allocate N zombies in a single allocation. this is a 
concept which shows the difference between creating one object and creating an entire
array of them at once
*/

int main()
{
	Zombie	*zombie;
	int		N;

	N = 10;
	zombie = zombieHorde(N, "Zombie");

	for (int i = 0; i < N; i++)
	{
		std::cout << "Index " << i << " ";
		zombie[i].announce();
	}
	delete [] zombie;
	return (0);
}
