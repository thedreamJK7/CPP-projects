#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:

		Fixed(void);
		Fixed(int const i);
		Fixed(float const f);
		Fixed(Fixed const &src);
		Fixed & operator = (Fixed const & rhs);
		~Fixed(void);

		bool				operator>(Fixed const & rhs) const;
		bool				operator< (Fixed const & rhs) const;
		bool				operator<= (Fixed const & rhs) const;
		bool				operator>= (Fixed const & rhs) const;
		bool				operator!= (Fixed const & rhs) const;
		bool				operator== (Fixed const & rhs) const;

		Fixed				operator + (Fixed const & rhs);
		Fixed				operator - (Fixed const & rhs);
		Fixed				operator * (Fixed const & rhs);
		Fixed				operator / (Fixed const & rhs);

		Fixed				&operator ++ ();
		Fixed				operator ++ (int);
		Fixed				&operator -- ();
		Fixed				operator -- (int);

		static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
		static Fixed const	&min(const Fixed &fixed1, const Fixed &fixed2);		
		static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
		static Fixed const	&max(const Fixed &fixed1, const Fixed &fixed2);		

		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;

	private:

		int					_value;
		static const	int	_fractionalBits = 8;
};

std::ostream & operator << (std::ostream & o, Fixed const & rhs);

#endif


