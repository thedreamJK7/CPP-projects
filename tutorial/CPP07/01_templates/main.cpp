#include <iostream>

template <typename T> // Template definition
T const &	max(T const & a, T const &b)
{
	return (a > b ? a : b);
}

int foo (int x)
{
	std::cout << "Compiling time!" << std::endl; 
}

int	main( void )
{
	int a = 42;
	int b = 21;

	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max<int>(a, b) << std::endl; // Explicit instansiation
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max(a, b) << std::endl; // Implicit instansiation

	float c = -1.7f;
	float d = 4.2f;
	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max<float>(c, d) << std::endl; // Explicit instansiation
	std::cout << "Max of " << c << " and " << d << " is ";
	std::cout << max(a, b) << std::endl; // Implicit instansiation	

	int ret = max<int>(foo(a), foo(b));
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << max<int>(a, b) << std::endl; // Explicit instansiation
}
