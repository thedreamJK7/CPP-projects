#include "Zombie.hpp"

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
