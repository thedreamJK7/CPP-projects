#ifndef SAMPLE_HPP
#define SAMPLE_HPP

#include <string>
#include <iostream>

class Student
{
	private:
		std::string	_login;
	
	public:
		Student(std::string login) : _login(login)
		{
			std::cout << "Student" << this->_login << " is born" << std::endl;
		}

		~Student()
		{
			std::cout << "Student" << this->_login << " died" << std::endl;
		}
};

#endif