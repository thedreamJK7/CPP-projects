#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *arr, int const length, F func)
{
	for (int i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T, typename F>
void iter(T const *arr, int const length, F func)
{
	for (int i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T>
void	print(T const &a)
{
	std::cout << a << " ";
}

template <typename T> void printArr(T *arr, int const &length)
{
	iter<T>(arr, length, print<T>);
	std::cout << std::endl;
}

template <typename T> void add(T &a) { a++; }

#endif