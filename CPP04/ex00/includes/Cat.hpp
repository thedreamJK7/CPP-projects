#ifndef Cat_HPP
#define Cat_HPP

#include "./includes/Animal.hpp"
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