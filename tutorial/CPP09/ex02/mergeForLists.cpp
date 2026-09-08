#include <iostream>
#include <list>
#include <iterator>

class Merge {
public:
	Merge() {};
	~Merge() {};

	typedef	std::list<int>::iterator 		it;
	
	void print(std::list<int>& head) {
		std::list<int>::const_iterator it = head.begin();
		while (it != head.end()) {
			std::cout << *it << std::endl;
			it++;
		}
	}
	static void merge(std::list<int> &right, std::list<int> &left, std::list<int> &head) {
		while (!left.empty() && !right.empty()) {
			if (left.front() <= right.front())
				head.splice(head.end(), left, left.begin());
			else
				head.splice(head.end(), right, right.begin());
		}
		head.splice(head.end(), left);
		head.splice(head.end(), right);
	}
	void mergeSort(std::list<int>& head) {
		if (head.size() <= 1)
			return ;
		it	middle = head.begin();
		std::advance(middle, head.size() / 2);
		std::list<int> left;
		std::list<int> right;
		left.splice(left.begin(), head, head.begin(), middle);
		right.splice(right.begin(), head);
		mergeSort(left);
		mergeSort(right);
		merge(right, left, head);
	}
private:
	Merge(const Merge& rhs) {
		*this = rhs;
	}
	Merge &operator=(const Merge& rhs) {
		if (this != &rhs)
			return *this;
		*this = rhs;
		return *this;
	}
};

// 4, -24, 25, 48, -1000
int main () {
	std::list<int> nums = {4, -24, 25, 48, -1000};

	Merge m;
	m.mergeSort(nums);
	m.print(nums);
	return (0);
}