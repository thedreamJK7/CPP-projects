#include <iostream>

int main()
{
	float a = 420.042f;

	void *b = &a;
	int *c = reinterpret_cast<int *> (b);
	std::cout << *c << std::endl;
	return 0;
}
