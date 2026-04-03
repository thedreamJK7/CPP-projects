#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(const std::string &name);

		Zombie();
		~Zombie();

		void		announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif