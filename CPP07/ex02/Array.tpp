#include "Array.hpp"

template <typename T> Array<T>::Array(): _data(NULL), _size(0) {};

template <typename T> Array<T>::Array(unsigned int & length)
: _data(new T[length]()), _size(length)
{ }

template <typename T> Array<T>::Array(Array<T> const &rhs)
{
	
}


