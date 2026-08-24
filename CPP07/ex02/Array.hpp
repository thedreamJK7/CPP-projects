#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T> class Array
{
	private:
		T 				*_data;
		unsigned int	_size;

	public:
		Array (); // default
		Array (unsigned int size); // parametrized
		Array (Array<T> const &rhs); // copy
		~Array (); // destructor

		Array &operator= (Array<T> const & rhs); // assign operator
		T	&operator[] (unsigned int index);
		
		unsigned int size() const; // size
		
		void	print( void );

		// exception
		class outOfIndex: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
// do not forget to include tpp file at the end of hpp file
#include "Array.tpp"

#endif