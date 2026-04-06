#include "Fixed.hpp"

// ==================== Constructors ==========================

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i): _value(i << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

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

// ==================== Destructor ==========================

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// ==================== Accessors ==========================

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

// ==================== Changing the data type ==========================

float	Fixed::toFloat( void ) const
{
	return (this->_value / (float)(1 << _fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (this->_value >> _fractionalBits);
}

// ==================== overload operators ==========================

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

// ==================== Operators ==========================

Fixed & Fixed::operator = (Fixed const & rhs)
{
	std::cout << "Copy assignment operator called " << std::endl;
	
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	
	return *this;
}

// ==================== Comparision operators ==========================

bool	Fixed::operator > (Fixed const & rhs) const
{
	return (_value > rhs._value);
}

bool	Fixed::operator < (Fixed const & rhs) const
{
	return (_value < rhs._value);
}

bool	Fixed::operator >= (Fixed const & rhs) const
{
	return (_value >= rhs._value);
}

bool	Fixed::operator <= (Fixed const & rhs) const
{
	return (_value <= rhs._value);
}

bool	Fixed::operator == (Fixed const & rhs) const
{
	return (_value == rhs._value);
}

bool	Fixed::operator != (Fixed const & rhs) const
{
	return (_value != rhs._value);
}

// ==================== Arithmetic operators ==========================

Fixed	Fixed::operator + (Fixed const & rhs)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + rhs.getRawBits());

	return result;
}

Fixed	Fixed::operator - (Fixed const & rhs)
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - rhs.getRawBits());

	return result;
}

Fixed	Fixed::operator * (Fixed const & rhs)
{
	Fixed	result;

	result.setRawBits((this->getRawBits() * rhs.getRawBits()) >> _fractionalBits);

	return result;
}

Fixed	Fixed::operator / (Fixed const & rhs)
{
	Fixed	result;

	if (rhs.getRawBits() == 0)
		return (Fixed(0));
	
	result.setRawBits((this->getRawBits() >> _fractionalBits) / rhs.getRawBits());

	return result;
}

// ==================== Increment / Decrement ==========================

/* Pre increment ++value */
Fixed	&Fixed::operator ++ ()
{
	this->_value++;
	return *this;
}

/* Post increment value++ */
Fixed	Fixed::operator ++ (int)
{
	Fixed temp(*this);
	this->_value++;
	return temp;
}

/* Pre decrement --value */
Fixed	&Fixed::operator -- ()
{
	this->_value--;
	return *this;
}

/* Post decrement value++ */
Fixed	Fixed::operator -- (int)
{
	Fixed temp(*this);
	this->_value--;
	return temp;
}

// ==================== Special functions ==========================

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	
	return fixed2;
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	
	return fixed2;
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return fixed1;
	
	return fixed2;
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return fixed1;
	
	return fixed2;
}


