#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(const char* argv[]): _leftover(-1) {
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

static int jacobNumber(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobNumber(n - 1) + 2 * jacobNumber(n - 2);
}

static std::vector<int> jacobsthalSequence(int pendingSize) {
	std::vector<int>	jacobsequence;
	std::vector<int>	insertedIndex;
	int					index = 3;

	if (pendingSize == 0)
		return insertedIndex;

	int value = jacobNumber(index);	
	while (pendingSize - 1 > value)
	{
		jacobsequence.push_back(value);
		value = jacobNumber(++index);
	}
	int prevJacobNum = 1;
	for (int i = 0; i < jacobsequence.size(); i++)
	{
		insertedIndex.push_back(jacobsequence[i]);
		for (int j = jacobsequence[i] - 1; prevJacobNum < j; j--)
			insertedIndex.push_back(j);
		prevJacobNum = jacobsequence[i];
	}
	while (prevJacobNum < --pendingSize) {
		insertedIndex.push_back(pendingSize);
	}
	return (insertedIndex);
}

static int binarySearch(std::vector<int>& arr, int target, int bound) {
	int	low = 0;
	int high = bound - 1;
	int mid;
	while (high >= low) {
		mid = low + (high - low) / 2;

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
	return (mid);
}

static int binarySearchPair(std::vector<Pair>& arr, int target) {
	int	low = 0;
	int high = arr.size() - 1;
	int mid;
	while (high >= low) {
		mid = low + (high - low) / 2;

		if (arr[mid].small == target) {
			return arr[mid].large;
		}

		if (arr[mid].small < target) {
			low = mid + 1;
		}

		if (arr[mid].small > target) {
			high = mid - 1;
		}
	}
	return (arr[mid].large);
}

void PmergeMeVector::mergeInsertion() {
	_mainChain.insert(_mainChain.begin(), _unsorted[0]);
	std::vector<int>	indSeq = jacobsthalSequence(_unsorted.size());
	
	for (std::vector<int>::iterator it = indSeq.begin(); indSeq.end() != it; it++)
	{
		int partner = binarySearchPair(_pairs, _unsorted[*it - 1]);
		int lastPos = binarySearch();
	}	
}
