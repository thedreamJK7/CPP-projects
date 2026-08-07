#include "../includes/Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat b1("B1", 149);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		/*
		or 
		try {
			Bureaucrat john("John", 0);
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Handled high grade: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Handled low grade: " << e.what() << std::endl;
		}
		*/
	}
	{
		try {
			Bureaucrat employee0("test", 1);
			std::cout << employee0 << std::endl;
			employee0.decrementGrade();
			std::cout << employee0 << std::endl;
			employee0.incrementGrade();
			//employee0.incrementGrade();
			std::cout << employee0 << std::endl;
			Bureaucrat employee1("too low", 151);
			Bureaucrat employee2("too high", -1);
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cerr << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
