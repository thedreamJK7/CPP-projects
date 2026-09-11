#include "PmergeMeVector.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		std::cout << "Error" << std::endl; 
		return (1);
	}
	try {
		clock_t start = clock();
		PmergeMeVector vec(++argv);
		vec.printBefore();
		vec.sort();
		vec.printAfter();
		clock_t end = clock();
			std::cout << "Time with std::vector: " << static_cast<double>(end - start) / 1000 << " millisec" << std::endl << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
