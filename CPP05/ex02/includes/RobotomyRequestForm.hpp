#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(); // Default constructor
		RobotomyRequestForm(const std::string & name); // constructor
		RobotomyRequestForm(RobotomyRequestForm const &rhs); // copy constructor
		RobotomyRequestForm & operator = (RobotomyRequestForm const &rhs); // assignemnt operator
		~RobotomyRequestForm(); // destructor

		// Setters & Getters
		const std::string	&getTarget() const;

		// Methods
		void execute(Bureaucrat const & executor) const;
};

#endif