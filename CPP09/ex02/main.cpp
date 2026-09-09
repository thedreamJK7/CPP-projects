#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		std::cout << "Error" << std::endl; 
		return (1);
	}
	try {
		PmergeMeVector vec(++argv);

		vec.print();
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
