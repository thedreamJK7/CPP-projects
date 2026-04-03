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

/*
** zombieHorde takes name by value, causing an extra string copy for each call. 
** Consider taking const std::string& name in both the declaration and definition to avoid unnecessary copying.
*/
Zombie* zombieHorde( int N, std::string name );

#endif