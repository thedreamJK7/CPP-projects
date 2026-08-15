#include "../includes/Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return	"Grade too HIGH:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return	"Grade too LOW:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}

Bureaucrat::Bureaucrat(const std::string & name, int grade)
: _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & rhs): _name(rhs._name), _grade(rhs._grade)
{ }

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs)
{
	_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {  };

const std::string &Bureaucrat::getName(void) const
{
	return (_name);
}

const int &Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::decrementGrade(void)
{
	int temp = _grade + 1;

	if (temp > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::incrementGrade(void)
{
	int temp = _grade - 1;

	if (temp < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &member)
{
	os << member.getName() << ", bureaucrat grade " << member.getGrade();
	return (os);
}