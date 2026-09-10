#include "PmergeMeVector.hpp"

namespace {
	static void merge(std::vector<Pair> &left, std::vector<Pair> &right, std::vector<Pair> &nums) {
		int lenL = left.size(), l = 0;
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

	static void	mergeSort(std::vector<Pair> &nums) {
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

	static int jacobsthal(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
	}

	static std::vector<int> jacobsthalSequence(size_t pendingSize) {
		std::vector<int>	jacobsequence;
		std::vector<int>	insertedIndex;
		int					index = 3;

		if (pendingSize == 0)
			return insertedIndex;
		int value = jacobsthal(index);
		while ((int)pendingSize > value)
		{
			jacobsequence.push_back(value);
			index++;
			value = jacobsthal(index);
		}
		size_t prevJacobNum = 1;
		for (size_t i = 0; i < jacobsequence.size(); i++)
		{
			insertedIndex.push_back(jacobsequence[i]);
			for (size_t j = jacobsequence[i] - 1; prevJacobNum < j; j--)
				insertedIndex.push_back(j);
			prevJacobNum = jacobsequence[i];
		}
		for (size_t j = pendingSize; j > prevJacobNum; j--)
			insertedIndex.push_back(j);
		return (insertedIndex);
	}
}

/* Constructor and destructor */
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

void PmergeMeVector::sort() {
	makePair();
	sortPairsByLarge();
	buildMainChain();
	mergeInsertion();
}

/* STEP 1: Make pairs and sort in ascending order inside each pair */

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

/* STEP 2: Merge Sort the pairs according to the first (biggest) value */

void PmergeMeVector::sortPairsByLarge() {
	mergeSort(_pairs);
}

// STEP 3: Set the sorted sequence
void PmergeMeVector::buildMainChain() {
	for (std::vector<Pair>::iterator it = _pairs.begin(); it < _pairs.end(); it++)
	{
		_mainChain.push_back((*it).large);
		_unsorted.push_back((*it).small);
	}
}

/* STEP 4: Insertion sort with comparison optimization using Jacobsthal sequence */
void PmergeMeVector::mergeInsertion() {
	// b1 is always <= a1, insert it at the front without binary search
	_mainChain.insert(_mainChain.begin(), _unsorted[0]);
	std::vector<int>	indSeq = jacobsthalSequence(_unsorted.size());
	
	for (std::vector<int>::iterator it = indSeq.begin(); indSeq.end() != it; it++)
		insertPending(_unsorted[*it - 1]);
	if (_leftover != -1)
	{
		int insertPos = binarySearch(_leftover, _mainChain.size());
		_mainChain.insert(_mainChain.begin() + insertPos, _leftover);
	}
}

int  PmergeMeVector::binarySearch(int target, int bound) const {
	int	low = 0;
	int high = bound - 1;
	int mid;
	while (high >= low) {
		mid = low + (high - low) / 2;
		if (_mainChain[mid] == target)
			return mid;
		if (_mainChain[mid] < target)
			low = mid + 1;
		if (_mainChain[mid] > target)
			high = mid - 1;
	}
	return (low);
}

int PmergeMeVector::findPartner(int pendingVal) const {
	int	low = 0;
	int high = _mainChain.size() - 1;
	int mid;
	while (high >= low) {
		mid = low + (high - low) / 2;
		if (_pairs[mid].small == pendingVal)
			return _pairs[mid].large;
		if (_pairs[mid].small < pendingVal)
			low = mid + 1;
		if (_pairs[mid].small > pendingVal)
			high = mid - 1;
	}
	return (-1);
}

void PmergeMeVector::insertPending(int value) {
	int partner = findPartner(value);
	int upperBound = binarySearch(partner, _mainChain.size());
	int insertPos = binarySearch(value, upperBound);
	_mainChain.insert(_mainChain.begin() + insertPos, value);
}
