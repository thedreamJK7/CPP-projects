#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
class Cat: public Animal
{
	public:
		Cat();
		Cat(std::string const & name);
		Cat(Cat const & src);
		Cat& operator=(Cat const & src);
		~Cat();

		virtual void	makeSound(void) const;
};

#endif