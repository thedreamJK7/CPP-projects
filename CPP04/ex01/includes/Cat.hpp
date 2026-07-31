#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat();
		Cat(std::string const & name);
		Cat(Cat const & src);
		Cat& operator=(Cat const & src);
		~Cat();

		virtual void	makeSound(void) const;
};

#endif