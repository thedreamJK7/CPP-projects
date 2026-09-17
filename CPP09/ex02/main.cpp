#include "./includes/PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2 || argc > 3001) {
		std::cout << "Error" << std::endl; 
		return (1);
	}
	{
		try {
			PmergeMe< std::vector<int> > vec(argv + 1);
			vec.printBefore();
			clock_t start = clock();
			vec.insertionSort();
			clock_t end = clock();
			std::cout << "Time: " << static_cast<double>(end - start) / 1000 << " millisec" << std::endl;
			vec.printAfter();
		} catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
