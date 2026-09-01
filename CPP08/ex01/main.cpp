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
	return 0;
}