#include <iostream> // input output stream
#include <map>		// A map stores elements in "key/value" pairs. 
#include <vector>	
/*
	A vector in C++ is like a resizable array.
	Both vectors and arrays are data structures used to store multiple elements of the same data type.
	The difference between an array and a vector, is that 
	the size of an array cannot be modified (you cannot add or remove elements from an array). 
	A vector however, can grow or shrink in size as needed.
*/
#include <list>
/*
	A list is similar to a vector in that it can store multiple elements of the same type and dynamically grow in size.
	However, two major differences between lists and vectors are:

	1. You can add and remove elements from both the beginning and at the end of a list, 
		while vectors are generally optimized for adding and removing at the end.

	2. Unlike vectors, a list does not support random access, meaning you cannot directly 
		jump to a specific index, or access elements by index numbers. 
*/
#include <string>

class IOperation;

int main( void )
{
	{
		std::list<int>	lst1;
		lst1.push_back(1);
		lst1.push_back(42);
		lst1.push_back(84);
		lst1.push_front(0);

		for (int num: lst1)
			std::cout << num << std::endl;

		// Create a list called cars that will store strings
		std::list<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
		
		// Iterators
		std::list<std::string>::const_iterator	it;
		std::list<std::string>::const_iterator	ite = cars.end(); // end() points to one position after the last element in the vector

  		// Print list elements
		/*
		for (std::string car : cars)
			std::cout << car << "\n";
		*/
		for (it = cars.begin(); ite != it; it++)
			std::cout << *it << std::endl;
	}

	{
		std::map<std::string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };

		// The key for which data should be retrieved.
		std::cout << people.at("John") << std::endl;
		for (auto person: people)
			std::cout << person.first << " is " << person.second << std::endl;
	}

	{
		std::vector<int>	v1(42); // 42 elements and all of them are 0 default
		std::vector<int>	v2(42, 100); // 42 elements and all of them are 100 default

		v2[42] = 101; // bad behaviour
		std::cout << v2.back() << std::endl;
	}
	return (0);
}


