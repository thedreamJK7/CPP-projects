#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(std::string const & type);
		Dog(Dog const & src);
		Dog& operator=(Dog const & src);
		~Dog();

		virtual void	makeSound(void) const;
};

#endif