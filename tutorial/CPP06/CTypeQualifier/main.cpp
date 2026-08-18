#include <stdio.h>
#include <iostream>

int main ( void )
{
	int a = 42;
	// int &b = a;
	const int *b = &a; // implicitly adding const

	const int &c = a;
	int &d = a;
	d = 42;
	// a = 46;
	int *f = (int *)b; // explicitly removing const
	*f = 85;
	std::cout << *f << std::endl;
	return (0);
}
