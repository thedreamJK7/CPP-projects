#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

/*
The Orthodox Canonical Form ensures that our classes behave like built-in types
(like int or float) when they are copied or destroyed.
Default Constructor: Initializes the object to a default state (value 0). 
Copy Constructor: Creates a new object as a copy of an existing one. 
Copy Assignment Operator: Overloads the = operator to copy data from one existing object to another. 
Destructor: Handles the cleanup when the object is destroyed. 

*/

class Fixed
{
	public:

		Fixed(void);
		Fixed(Fixed const &src);
		Fixed & operator = (Fixed const & rhs);
		~Fixed(void);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

	private:

		int					_value;
		static const	int	_fractionalBits;
};


#endif


