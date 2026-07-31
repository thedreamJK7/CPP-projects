#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(std::string const & type);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal& operator=(WrongAnimal const & src);
		virtual ~WrongAnimal();

		void	makeSound(void) const;
};

#endif
