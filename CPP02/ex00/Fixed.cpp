#include "Fixed.hpp"

Fixed::Fixed(void): _fixed(0)
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
	std::cout << "Assignation operator called " << std::endl;
	
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits( int const raw )
{
	this->_fixed = raw / ( 2 ^ this->_fractionalBits);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed * ( 2 ^ this->_fractionalBits));
}
