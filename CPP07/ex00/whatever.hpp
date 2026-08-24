#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T, typename U>
void	swap(T &a, U &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T> T const &min(T const &a, T const &b)
{ return a > b ? b : a; }

template <typename T> T	const &max(T const &a, T const &b)
{ return a > b ? a : b; }

#endif