#ifndef Intern_H
#define Intern_H

#include "AForm.hpp"
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;
class Intern {

	public:
		Intern();                        // empty constructor
		Intern(Intern const &rhs);            // copy constructor
		Intern &operator=(Intern const &rhs); // copy assignment operator
		~Intern();                         // destructor

		AForm	*makeForm(const std::string &form_name, 
						const std::string &target_form);
		class invalidFormName: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		AForm	*shrubbery(const std::string &target_form);
		AForm	*presidential(const std::string &target_form);
		AForm	*request(const std::string &target_form);
};

#endif