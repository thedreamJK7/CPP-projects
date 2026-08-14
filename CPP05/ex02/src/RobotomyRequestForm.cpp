#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string & target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs)
: AForm(rhs), _target(rhs._target)
{ }

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		(*this)._target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
	if (executor.getGrade() < getGradeToSign())
		throw RobotomyRequestForm::GradeTooLowException();
	if (!getIsSigned())
		throw RobotomyRequestForm::FileNotSignedException();
	
	std::cout	<< "><><>< Bbbbzzzz zZaap BBbbbzz ><><><"
				<< std::endl;

	std::cout	<< executor.getName()	<< " has successfully executed form "
				<< this->getName()		<< std::endl;
}
