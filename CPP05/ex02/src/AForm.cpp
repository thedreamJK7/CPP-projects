#include "../includes/AForm.hpp"

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return	"Grade too HIGH:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return	"Grade too LOW:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

AForm::AForm()
    : _name("Generic"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

//constructor
AForm::AForm(const std::string & name, 
		const int & gradeToSign, const int & gradeToExecute)
: _name(name),
_isSigned(false),
_gradeToSign(gradeToSign), 
_gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1)
		throw AForm::GradeTooHighException();

	if (gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

//copy constructor
AForm::AForm(const AForm & rhs): 
_name(rhs._name),
_isSigned(rhs._isSigned),
_gradeToSign(rhs._gradeToSign),
_gradeToExecute(rhs._gradeToExecute)
{ }

// assignemt operator
AForm & AForm::operator=(const AForm &rhs)
{
	_isSigned = rhs._isSigned;
	return (*this);
}

// destructor
AForm::~AForm() {  }

// getters
const std::string	&AForm::getName(void) const
{
	return(_name);
}

const int	&AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

const int	&AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

bool	AForm::getIsSigned(void)	const
{
	return (_isSigned);
}

// operator overload
std::ostream	&operator<<(std::ostream &os, const AForm &Aform)
{
	os	<< "Name: "					<< Aform.getName ()
		<< "\nSignature status: "	<< Aform.getIsSigned ()
		<< "\nSignature grade: "	<< Aform.getGradeToSign ()
		<< "\nExecution grade: "	<< Aform.getGradeToExecute ();
	return (os);
}

// member functions
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

