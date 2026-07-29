#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
	private:
		int	_numOfLegs;
	
	public:
		Animal(); // constructor
		Animal(Animal const &src); // copy constructor, it is calling the assignment operator internally which is why it is copy all the data from src to new object
		Animal& operator=(Animal const &src); // assignment operator
		~Animal(); // destructor

		void	run(int	distance);
		void	call();
		void	eat(std::string	const & what);
		void	walk(int distance);
};

#endif