#include "Array.hpp"

// default constructor
template <typename T> Array<T>::Array(): _data(NULL), _size(0) {};

// parametrised constructor
template <typename T> Array<T>::Array(unsigned int length)
: _data(new T[length]()), _size(length)
{ }

// copy constructor
template <typename T> Array<T>::Array(Array<T> const &rhs)
{
	this->_size = rhs._size;
	this->_data = new T[rhs._size]();
	for (size_t i = 0; i < this->_size; i++)
	{
		this->_data[i] = rhs._data[i];
	}
}

// assignment operator
template <typename T> Array<T> & Array<T>::operator = (Array<T> const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->_size = rhs._size;
	delete[] this->_data;
	this->_data = new T[rhs._size]();

	for (size_t i = 0; i < this->_size; i++)
		this->_data[i] = rhs._data[i];
	return (*this);
}

// destructor
template <typename T> Array<T>::~Array()
{
	delete[] _data;
}

// exception
template <typename T>
const char* Array<T>::outOfIndex::what() const throw()
{
	return "Array index out of bound, exiting";
}

// Implementation of [] operator. This function must return
// a reference as array element can be put on left side
template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (_size <= index)
	{
		throw Array<T>::outOfIndex();
	}	
	return (_data[index]);
}

// size
template <typename T> unsigned int Array<T>::size() const { return _size; } 
