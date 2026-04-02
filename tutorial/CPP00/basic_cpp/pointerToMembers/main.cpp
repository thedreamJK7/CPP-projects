#include <iostream>
#include "sample.hpp"

int main()
{
	Sample	instance;
	// pointing to instance
	/*
		instance        instancep
		---------       ----------
		| data  |  <--- 0x12345 (address)
		---------
	*/
	Sample*	instancep = &instance;

	// pointer to member of class
	int		Sample::*p = NULL;
	// pointer to member function of class
	void	(Sample::*f)(void) const;

	p = &Sample::_foo;
	std::cout << "Value of member foo: " << instance._foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo: " << instance._foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance._foo << std::endl;
	
	f = &Sample::bar;
	// calling the function pointer by object
	(instance.*f)();
	// calling the function pointer by pointer
	(instancep->*f)();

	return (0);
}
