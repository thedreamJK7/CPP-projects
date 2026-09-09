#include <iostream>
#include <vector>

template <typename T>
static int binarySearch(std::vector<T>& arr, T target) {
	int	low = 0;
	int high = arr.size() - 1;
	int mid;
	while (high >= low) {
		mid = (low + high) / 2;

		if (arr[mid] == target) {
			return mid;
		}

		if (arr[mid] < target) {
			low = mid + 1;
		}

		if (arr[mid] > target) {
			high = mid - 1;
		}
	}
	return (-1);
}

int main(void)
{
	std::vector<std::string> nums = {"a", "b", "c", "d"};
	std::string a = "a";
	int index = binarySearch(nums, a);
	std::cout << index << std::endl;
	return (0);
}
