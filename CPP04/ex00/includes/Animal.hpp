#ifndef Animal_HPP
#define Animal_HPP

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
		~Animal();

		const			std::string	&getType() const;
		virtual void	makeSound(void) const;
};

#endif