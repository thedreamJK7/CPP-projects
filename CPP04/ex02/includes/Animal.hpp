#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(std::string const & name);
		Animal(Animal const & src);
		Animal& operator=(Animal const & src);
		virtual ~Animal();

		const			std::string	&getType() const;
		virtual void	makeSound(void) const = 0;
};

#endif