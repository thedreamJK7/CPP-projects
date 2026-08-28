#include <iostream>
#include <algorithm>
#include <list>


void displayInt(int & i)
{
	std::cout << i << std::endl;
}
int main(void)
{
	std::list<int> lst1;

	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);

	// Apply a function to every element of a sequence.
	for_each(lst1.begin(), lst1.end(), displayInt);
	return (0);
}
