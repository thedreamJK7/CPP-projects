#include "Span.hpp"

int main()
{
	{
		std::cout << "Test with 5 elements" << std::endl;
		try {
			Span sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(-17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << "Test with 10000 elements" << std::endl;
		try {
			Span sp(10000);
			std::srand(time(NULL));

			for (size_t i = 0; 10000 > i; i++ ) {
				sp.addNumber(std::rand() % 10000 + 1);
			}
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "Test with Group elements" << std::endl;
			Span sp(5);

			std::vector<int> v;
			v.push_back(10);
			v.push_back(20);
			v.push_back(30);

			sp.addGroup(v);

			std::vector<int> v2;
			v2.push_back(40);
			v2.push_back(50);

			sp.addGroup(v2);
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}