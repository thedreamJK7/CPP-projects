#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

/*

Defining the zombie class, the class has a private attribute _name, which stores
the name of the zombie, ensuring encapsulation(qobiqqa orash, himoyalash)

why is _name private:
To enforce encapsulation. It prevents direct modification from outside the class
 and ensures controlled access through member functions.
*/

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(const std::string &name);
		~Zombie();

		void		announce( void );
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif