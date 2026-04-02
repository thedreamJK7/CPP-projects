#include <iostream>
#include "sample.hpp"

int main()
{
	Student		bob = Student("Bob");
	Student*	jon = new Student("Jon");

	delete jon;
	return (0);
}
