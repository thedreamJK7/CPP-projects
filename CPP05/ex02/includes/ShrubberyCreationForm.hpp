#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(const std::string & target); // constructor
		ShrubberyCreationForm(ShrubberyCreationForm const &rhs); // copy constructor
		ShrubberyCreationForm & operator = (ShrubberyCreationForm const &rhs); // assignemnt operator
		~ShrubberyCreationForm(); // destructor

		// Setters & Getters
		const std::string	&getTarget() const;

		// Methods
		void execute(Bureaucrat const & executor) const;
};

#endif