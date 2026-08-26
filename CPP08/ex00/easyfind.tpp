#ifndef EASYFIND_CPP
#define EASYFIND_CPP

#include <iterator>
#include "easyfind.hpp"
#include <algorithm>
// An iterator is like a pointer that can move through elements in a container.
// return an ITERATOR to the found element
template<typename T>typename T::const_iterator easyfind(T const  &cont, int find)
{
	typename T::const_iterator it;

	it = std::find(cont.begin(), cont.end(), find);
	if (it == cont.end())
		throw notFoundException();
	return (it);
}

#endif