#include "easyfind.hpp"

int main(void)
{
	std::cout << "Iterate through Int-List" << std::endl;
	{
		try {
			std::list<int> lst;

			lst.push_back(10);
			lst.push_back(23);
			lst.push_back(3);
			lst.push_back(17);
			lst.push_back(20);
			std::list<int>::const_iterator it = easyfind(lst, 23);
			std::cout << *it << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << "Iterate through vector" << std::endl;
	{
		try
		{
			std::vector<int> lst;
			lst.push_back(11);
			lst.push_back(24);
			lst.push_back(43);
			lst.push_back(17);
			lst.push_back(28);

			std::cout << lst[2] << std::endl;
			std::vector<int>::const_iterator it = easyfind(lst, 23);
			std::cout << *(it - 1) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
