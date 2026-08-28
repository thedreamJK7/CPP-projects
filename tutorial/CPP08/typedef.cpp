#include <iostream>
#include <vector>
// typedef is like an alias, it allows u to create new name for an existing type
typedef struct s_test{
	int age;
	std::string name;
} 		test;

typedef	std::vector<int> IntVector;

int main( void )
{
	s_test person1;

	person1.age = 25;
	person1.name = "Stewe";

	IntVector v(5);

	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
		std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << std::endl;
	}
	std::cout << v[6] << std::endl;
	return (0);
}
