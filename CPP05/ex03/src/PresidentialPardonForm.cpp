#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs)
: AForm(rhs), _target(rhs._target)
{ }

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		(*this)._target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const 
{
	if (!getIsSigned())
		throw PresidentialPardonForm::FileNotSignedException();
	
	if (executor.getGrade() > getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();

	std::cout	<< this->_target	<< " has has been pardoned by Zaphod Beeblebrox"
				<< std::endl;

	std::cout	<< executor.getName()	<< " has successfully executed form "
				<< this->getName()		<< std::endl;
}
