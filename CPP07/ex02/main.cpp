#include "Array.hpp"

int main(void)
{
	std::cout << "Empty array!" << std::endl;
	{
		Array<int> a;
		std::cout << a.size() << std::endl;
	}
	std::cout << "Array with n elements!" << std::endl;
	{
		Array<int> a(5);
		std::cout << a.size() << std::endl;

		a.print();
	}
	std::cout << "Deep copy!" << std::endl;
	{
		Array<int> a(3);

		a[0] = 10;
		a[1] = 20;
		a[2] = 30;

		Array<int> b(a);

		b[0] = 999;
		a.print();
		b.print();
	}
	std::cout << "Out of bounds!" << std::endl;
	{
		try
		{
			Array<int> a(3);

			a[0] = 10;
			a[1] = 20;
			a[2] = 30;
			
			a.print();
			a[4] = 5;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
