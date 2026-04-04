#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>

class Integer
{
	private:
		int	_n;

	public:
		Integer( int const n );
		~Integer();
	
		int		getValue( void ) const;
	
		// Assignment operator =
		Integer &	operator=(Integer const & rhs);
		// Addition operator +
		Integer		operator+(Integer const & rhs) const;
};

// Output operator (<<)
std::ostream & operator << (std::ostream & o, Integer const & rhs);

#endif
