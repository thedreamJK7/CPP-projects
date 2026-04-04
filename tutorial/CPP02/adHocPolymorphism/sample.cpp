#include "sample.hpp"

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
}

void	Sample::bar(char const c) const
{
	std::cout << "Member function bar called with char overload: " << c << std::endl;
	return;
}

void	Sample::bar(int const n) const
{
	std::cout << "Member function bar called with int overload: " << n << std::endl;
	return;
}

void	Sample::bar(float const f) const
{
	std::cout << "Member function bar called with float overload: " << f << std::endl;
	return;
}

void	Sample::bar(Sample const & i) const
{
	( void ) i;
	std::cout << "Member function bar called with Sample overload: "  << std::endl;
	return;
}