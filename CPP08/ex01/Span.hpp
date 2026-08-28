#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
class Span
{
	private:
		std::vector<int>	_n;
		unsigned int		_size;
	
	public:
		Span(unsigned int & n);
		Span(Span const & rhs);
		Span & operator = (Span const & rhs);
		~Span();

		// exception
		class outOfRange: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif