#include "Mutantstack.hpp"

void subjext() {
	std::cout << "============== Subject example ==================" << std::endl; 

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void basic_iter(void) {
	std::cout << "============== Basic Iteration ==================" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);
	mstack.push(9);

	MutantStack<int>::iterator it = mstack.begin();
	while (*it)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

/*
┌──────┬──────┬──────┬──────┬────────┐
│  10  │  20  │  30  │  40  │ GARBAGE│
└──────┴──────┴──────┴──────┴────────┘
*/

void reverse_iter(void) {
	std::cout << "============== Reverse Iterator ==================" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(6);
	mstack.push(7);
	mstack.push(8);
	mstack.push(9);

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	std::cout << *rit << std::endl;
	MutantStack<int>::reverse_iterator rit_e = mstack.rend();
	std::cout << *(rit_e - 1) << std::endl;
	while (rit != rit_e) {
		std::cout << *rit << std::endl;
		rit++;
	}
}

int main()
{
	basic_iter();
	reverse_iter();
	return 0;
}