#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
copy constructor → calls operator= → copies value
*/
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator = (Fixed const & rhs)
{
	std::cout << "Copy assignment operator called " << std::endl;
	
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}


static const int _fractionalBits = 8;