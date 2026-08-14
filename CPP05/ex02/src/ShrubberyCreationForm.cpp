#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs)
: AForm(rhs), _target(rhs._target)
{ }

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		(*this)._target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

