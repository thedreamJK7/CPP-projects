#include "Vertex.class.tpp"
#include <iostream>

int main( void )
{
	Vertex<int> v1(12, 22, 42);
	Vertex<> v2(12, 22, 42);

	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	return 0;
}
