#include "../includes/PmergeMeVector.hpp"

// default constructor and destructor
PmergeMeVector::PmergeMeVector() {};
PmergeMeVector::~PmergeMeVector() {};

// parametrized constructor
PmergeMeVector::PmergeMeVector(const char* argv[]) {
	int		num;

	while (*argv != NULL) {
		std::stringstream ss(*argv);
		ss >> num;

		if (ss.fail() || !ss.eof() || num < 0)
			throw Error();
		t_num	n_struct;
		n_struct.num = num;
		n_struct.ptr_pair = nullptr;
		unsorted_nums.push_back(n_struct);
		argv++;
	}
}

// i) Make pairwise comparisons of [n / 2] disjoint pairs of elements. (If n is odd,
// leave one element out.)
// ii) Sort the [n/2] larger numbers, found in step (i), by merge insertion.
// iii) insert pending elements based on jacobsthal sequece
std::vector<t_num> merge_insertion_sort(std::vector<t_num>& nums) {
	if (nums.size() < 1) {
		return nums;
	}
	// pair the elements if odd save the leftover
	std::vector<t_pairs>	pairs;
	t_pairs					s_pair;
	int	leftover = -1;
	int len = nums.size();
	if (len % 2 == 1) {
		leftover = nums[len - 1].num;
		len--;
	}
	for (int i = 0; i < len; i += 2) {
		if (nums[i].num > nums[i + 1].num) {
			s_pair.winners = &nums[i];
			s_pair.losers = &nums[i + 1];
			nums[i + 1].ptr_pair = &nums[i];
		} else {
			s_pair.winners = &nums[i + 1];
			s_pair.losers = &nums[i];
			nums[i].ptr_pair = &nums[i + 1];
		}
		pairs.push_back(s_pair);
	}

	
}

