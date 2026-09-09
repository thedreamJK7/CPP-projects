#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(const char* argv[]) {
	int	num;

	while (*argv != NULL) {
		std::stringstream ss(*argv);
		ss >> num;

		if (ss.fail() || !ss.eof() || num < 0)
			throw Error();
		_nums.push_back(num);
		argv++;
	}
}

PmergeMeVector::~PmergeMeVector() { };

void PmergeMeVector::makePair(void) {
	Pair 						pair;
	std::vector<int>::iterator	it = _nums.begin();
	std::vector<int>::iterator	pairEnd;
	std::vector<int>::iterator	first;
	if (_nums.size() % 2 == 1)
	{
		pairEnd = --_nums.end();
		_leftover = *pairEnd;
	} else {
		pairEnd = _nums.end();
	}

	while (it != pairEnd)
	{
		first = it;
		it++;
		if (*first >= *it) {
			pair.large = *first;
			pair.small = *it;
		} else {
			pair.large = *it;
			pair.small = *first;	
		}
		_pairs.push_back(pair);
		it++;
	}
}

static void merge(std::vector<Pair> &left, std::vector<Pair> &right, std::vector<Pair> &nums) {
	int lenL = left.size(), l = 0;;
	int lenR = right.size(), r = 0;
	int i = 0;
	while (lenL > l && lenR > r)
	{
		if (left[l].large > right[r].large) {
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

static void  mergeSort(std::vector<Pair> &nums) {
	int	len = nums.size();
	if (len == 1) {
		return ;
	}
	int middle = len / 2;
	std::vector<Pair> left;
	std::vector<Pair> right;
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

void PmergeMeVector::buildMainChain() {
	mergeSort(_pairs);

	for (std::vector<Pair>::iterator it = _pairs.begin(); it < _pairs.end(); it++)
	{
		_mainChain.push_back((*it).large);
		_unsorted.push_back((*it).small);
	}
}

