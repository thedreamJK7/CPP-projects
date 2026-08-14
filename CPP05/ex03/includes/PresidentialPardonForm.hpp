#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(); // Default constructor
		PresidentialPardonForm(const std::string & name); // constructor
		PresidentialPardonForm(PresidentialPardonForm const &rhs); // copy constructor
		PresidentialPardonForm & operator = (PresidentialPardonForm const &rhs); // assignemnt operator
		~PresidentialPardonForm(); // destructor

		// Setters & Getters
		const std::string	&getTarget() const;

		// Methods
		void execute(Bureaucrat const & executor) const;
};

#endif