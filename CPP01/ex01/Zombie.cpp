#include "Zombie.hpp"

/*
** default constructor is important when trying to create bunch of objects.
** new Zombie[5] must be able to construct each element with 
** no extra info, so it calls the default constructor 5 times.
** If your class has only Zombie(std::string const&) and no Zombie(), then 
** this fails because C++ doesn’t know what name to pass for each element.
*/
Zombie::Zombie(): _name("Unnamed")
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called" << std::endl;
}

void Zombie::setName(const std::string &name)
{
	_name = name;
}

void	Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
