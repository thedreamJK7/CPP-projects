#include <iostream>
#include <vector>

class Merge {
public:
	Merge() {};
	~Merge() {};

	void print(std::vector<int> &nums) {
		for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			std::cout << *it << std::endl;
		}
	};

	static void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &nums) {
		int lenL = left.size(), l = 0;;
		int lenR = right.size(), r = 0;
		int numsL = nums.size(), i = 0;
		while (lenL > l && lenR > r)
		{
			if (left[l] > right[r]) {
				nums[i] = right[r];
				r++;
			} else {
				nums[i] = left[l];
				l++;
			}
			i++;
		}
		while(lenL > l) {
			nums[i] = left[l];
			l++;
			i++;
		}
		while(lenR > r) {
			nums[i] = right[r];
			r++;
			i++;
		}
	}

	void mergeSort(std::vector<int> &nums) {
		int	len = nums.size();
		if (len == 1) {
			return ;
		}
		int middle = len / 2;
		std::vector<int> left;
		std::vector<int> right;
		for (int i = 0; len > i; i++) {
			if (middle > i)
				left.push_back(nums[i]);
			else
				right.push_back(nums[i]);
		}
		mergeSort(left);
		mergeSort(right);
		merge(left, right, nums);
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

int main () {
	std::vector<int> nums = {4, -24, 25, 48, -1000};

	Merge m;
	m.mergeSort(nums);
	m.print(nums);
	return (0);
}