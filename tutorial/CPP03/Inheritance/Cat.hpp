#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(Cat const &);
		Cat& operator=(Cat const &);
		~Cat();
	
		void	scornTarget(std::string	const & target);
};

#endif