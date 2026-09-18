#include "./includes/PmergeMe.hpp"
#include <deque>
#include <ctime>

int main(int argc, char const *argv[])
{
	if (argc < 2 || argc > 3001) {
		std::cout << "Error" << std::endl;
		return (1);
	}
	try {
		PmergeMe< std::vector<int> > vec(argv + 1);
		PmergeMe< std::deque<int> >  deq(argv + 1);

		vec.printBefore();

		clock_t startV = clock();
		vec.insertionSort();
		clock_t endV = clock();

		clock_t startD = clock();
		deq.insertionSort();
		clock_t endD = clock();

		vec.printAfter();
		std::cout << "Time with std::vector : "
			<< static_cast<double>(endV - startV) / 1000 << " ms" << std::endl;
		std::cout << "Time with std::deque  : "
			<< static_cast<double>(endD - startD) / 1000 << " ms" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
