#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// i * 256
Fixed::Fixed(const int i): _value(i << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

// f * 256
Fixed::Fixed(const float f): _value(roundf(f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
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
	return (this->_value);
}
// value / 256
float	Fixed::toFloat( void ) const
{
	return (this->_value / (float)(1 << _fractionalBits));
}

// value / 256
int		Fixed::toInt( void ) const
{
	return (this->_value >> _fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
