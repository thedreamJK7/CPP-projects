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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
	if (!getIsSigned())
		throw ShrubberyCreationForm::FileNotSignedException();

	if (executor.getGrade() > getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenedException();
	else
	{
		file << 
		"        /\\                /\\               /\\\n"
		"       /**\\              /**\\             /**\\\n"
		"      /****\\            /****\\           /****\\\n"
		"     /******\\          /******\\         /******\\\n"
		"    /********\\        /********\\       /********\\\n"
		"       ||                ||               ||\n"
		"\n"
		"               /\\\n"
		"              /**\\\n"
		"             /****\\\n"
		"            /******\\\n"
		"           /********\\\n"
		"              ||\n"
		"\n"
		"   _\\|/_\n"
		"   (> <)\n"
		"   /   \\\n";
	}
	file.close();

	std::cout	<< executor.getName()	<< " has successfully executed form "
				<< this->getName()		<< std::endl;
}

