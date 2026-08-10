#include "../includes/Form.hpp"

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return	"Grade too HIGH:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return	"Grade too LOW:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

//constructor
Form::Form(const std::string & name, 
		const int & gradeToSign, const int & gradeToExecute)
: _name(name),
_isSigned(false),
_gradeToSign(gradeToSign), 
_gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1)
		throw Form::GradeTooHighException();

	if (gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

//copy constructor
Form::Form(const Form & rhs): 
_name(rhs._name),
_isSigned(rhs._isSigned),
_gradeToSign(rhs._gradeToSign),
_gradeToExecute(rhs._gradeToExecute)
{ }

// assignemt operator
Form & Form::operator=(const Form &rhs)
{
	_isSigned = rhs._isSigned;
	return (*this);
}

// destructor
Form::~Form() {  }

// getters
const std::string	&Form::getName(void) const
{
	return(_name);
}

const int	&Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

const int	&Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

bool	Form::getIsSigned(void)	const
{
	return (_isSigned);
}

// operator overload
std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os	<< "Name: "					<< form.getName ()
		<< "\nSignature status: "	<< form.getIsSigned ()
		<< "\nSignature grade: "	<< form.getGradeToSign ()
		<< "\nExecution grade: "	<< form.getGradeToExecute ();
	return (os);
}

// member functions
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

