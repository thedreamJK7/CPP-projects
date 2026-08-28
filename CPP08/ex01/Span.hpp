#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {	
	public:
		Span(const unsigned int n);
		Span(Span const & rhs);
		Span & operator = (Span const & rhs);
		~Span();

		// exception
		class outOfRange: public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return "Out of range!";
				}
		};
		class noSpan: public std::exception
		{
			public:
				virtual const char *what() const throw() {
					return "No span for items with elements'count less than 2";
				}
		};

		// getter, setter
		unsigned int	getSize() const { return _size; };
		unsigned int	getCounter() const { return _counter; };
		void			printAll(std::vector<int> &data) const {
			for (size_t i = 0; i < _counter; i++)
				std::cout << data[i] << " ";
			std::cout << std::endl;
		};

		void			addNumber(int n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
	private:
		std::vector<int>	_n;
		unsigned int		_size;
		unsigned int		_counter;
};

#endif