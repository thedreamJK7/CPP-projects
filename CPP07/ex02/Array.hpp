#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
	private:
		T 				*_data;
		unsigned int	_size;

	public:
		Array ();
		Array (unsigned int &size);
		Array (Array<T> const &rhs);
		Array &operator= (Array<T> const & rhs);
};

#endif