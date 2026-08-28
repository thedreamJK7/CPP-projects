#include "Span.hpp"

Span::Span(const unsigned int n): _size(n), _counter(0) { }

Span::Span(Span const &rhs): _size(rhs._size), _counter(rhs._counter) { 
	this->_n = rhs._n;
}

Span & Span::operator=(Span const &rhs) {
	if (this == &rhs) {
		return (*this);
	}

	this->_size = rhs._size;
	this->_counter = rhs._counter;
	this->_n = rhs._n;

	return (*this);
}

Span::~Span() { }

void	Span::addNumber(int n) {
	if (_size >= ++_counter)
		_n.push_back(n);
	else
		throw Span::outOfRange();
}

unsigned int	Span::shortestSpan(void) {
	int	dif;
	int span;
	
	if (_counter < 2) {
		throw Span::noSpan();
	}
	std::vector<int> tmp(_n);
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i < _counter - 1; i++)
	{
		dif = std::abs(tmp[i] - tmp[i+1]);
		if (dif == 0)
			return (0);
		if (i == 0)
			span = dif;
		if (span > dif)
			span = dif;
	}
	return (span);
}

unsigned int	Span::longestSpan(void) {
	if (_counter < 2) {
		throw Span::noSpan();
	}
	
	std::vector<int> tmp(_n);
	std::sort(tmp.begin(), tmp.end());
	return (std::abs(tmp[0] - tmp[tmp.size() - 1]));
}

