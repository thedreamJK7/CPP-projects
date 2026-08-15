#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &rhs)
{
	(void)rhs;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern(){}

AForm *Intern::shrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::presidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::request(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

const char *Intern::invalidFormName::what() const throw()
{
	return "Invalid form name \n";
} 

AForm *Intern::makeForm(const std::string &form_type, 
						const std::string &target)
{
	std::string	forms[] = {"shrubbery creation", "presidential pardon", "robotomy request"};
	// Array of Function Pointers
	AForm* (Intern::*pointers[])(const std::string &) = {
		&Intern::shrubbery,
		&Intern::presidential,
		&Intern::request
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form_type)
		{
			std::cout << "Intern creates " << form_type
                << std::endl;
			return ((this->*pointers[i])(target));
		}
	}
	throw Intern::invalidFormName();	
	return (NULL);
}
