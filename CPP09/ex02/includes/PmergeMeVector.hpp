#ifndef PMERGEMEVECTOR_H
#define PMERGEMEVECTOR_H

#include <vector>
#include <string>
#include <exception>
#include <sstream>

// Number struct
typedef struct	s_num {
	unsigned int	num;
	const t_num*	ptr_pair; 
}				t_num;

// pair struct
typedef struct s_pairs
{
	t_num*	winners;
	t_num*	losers;	
}	t_pairs;


class PmergeMeVector {
public:
	PmergeMeVector(const char* argv[]);
	~PmergeMeVector();

	class Error: public std::exception {
		virtual const char* what() const throw() {
			return "Error";
		};
	};
private:
	std::vector<t_num>	unsorted_nums;
	std::vector<t_num>	sorted_nums;
	int 				comparisions;

	PmergeMeVector();
	PmergeMeVector& operator = (const PmergeMeVector&);
	PmergeMeVector(const PmergeMeVector&);
};

#endif 