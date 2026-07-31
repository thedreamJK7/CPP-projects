#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string const & name);
		WrongCat(WrongCat const & src);
		WrongCat& operator=(WrongCat const & src);
		~WrongCat();

		void	makeSound(void) const;
};

#endif
