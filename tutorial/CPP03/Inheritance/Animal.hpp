#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
	private:
		int	_numOfLegs;
	
	public:
		Animal();
		Animal(Animal const &src);
		Animal& operator=(Animal const &src);
		~Animal();

		void	run(int	distance);
		void	call();
		void	eat(std::string	const & what);
		void	walk(int distance);
};

#endif