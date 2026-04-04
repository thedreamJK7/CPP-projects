#include "integer.hpp"

Integer::Integer(int const n): _n(n)
{
	std::cout << "Constructor called with value " << this->_n << std::endl;
}

Integer::~Integer()
{
	std::cout << "Destructor called with value " << this->_n << std::endl;
}


int		Integer::getValue( void ) const
{
	return (this->_n);
}

/*
	Copies value from rhs to this
	Returns reference → allows chaining (a = b = c)
*/

Integer & Integer::operator=(Integer const & rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;

	this->_n = rhs.getValue();

	return *this;
}

/*
	Handles: a + b;
	Creates a new object with:
	this->_n + rhs._n
	Does NOT modify original objects
*/

Integer	Integer::operator+(Integer const & rhs) const
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;

	return Integer(this->_n + rhs.getValue());
}

/*
	Prints _n to output
	It’s outside the class because std::cout is not your class
*/

std::ostream & operator<<(std::ostream & o, Integer const & rhs)
{
	o << rhs.getValue();
	return (o);
}
