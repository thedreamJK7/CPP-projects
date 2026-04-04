#ifndef SAMPLE_HPP
#define SAMPLE_HPP

#include <iostream>

class Sample
{
	private:
		
	public:
		Sample();
		~Sample();

		void	bar(char const c) const;
		void	bar(int const n) const;
		void	bar(float const z) const;
		void	bar(Sample const & i) const;

};

#endif