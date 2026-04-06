#include "Fixed.hpp"

// ==================== Constructors ==========================

Fixed::Fixed(void): _value(0)
{
}

Fixed::Fixed(const int i): _value(i << _fractionalBits)
{
}

Fixed::Fixed(const float f): _value(roundf(f * (1 << _fractionalBits)))
{
}

/*
copy constructor → calls operator= → copies value
*/
Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

// ==================== Destructor ==========================

Fixed::~Fixed(void)
{
}

// ==================== Accessors ==========================

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

int	Fixed::getRawBits( void ) const
{
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

	result.setRawBits((this->getRawBits() * long(rhs.getRawBits())) >> _fractionalBits);

	return result;
}

Fixed	Fixed::operator / (Fixed const & rhs)
{
	Fixed	result;

	if (rhs.getRawBits() == 0)
		return (Fixed(0));
	
	result.setRawBits((long(this->getRawBits()) >> _fractionalBits) / rhs.getRawBits());

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
	if (fixed1._value < fixed2._value)
		return fixed1;
	
	return fixed2;
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1._value < fixed2._value)
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


