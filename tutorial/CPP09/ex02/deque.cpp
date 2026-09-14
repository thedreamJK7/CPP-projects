#include <deque> // FIFO
#include <iostream> // input, output stream

int main() {
	std::deque<int> d = {1, 2, 3, 4, 5};

	d.push_back(6); // add in the beginning of 
	d.push_front(0); // add at the end of array
	d.pop_back(); // removing the element from back
	d.pop_front(); // removing the element from beginning
	for (int i: d) {
		std::cout << i << std::endl;
	}	
	return (0);
}
