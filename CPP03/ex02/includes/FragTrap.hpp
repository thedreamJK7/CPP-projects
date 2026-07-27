#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap:public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const & name);
		FragTrap(FragTrap const &src);
		FragTrap& operator=(FragTrap const &src);
		~FragTrap();

		void				highFivesGuys(void);
};

#endif