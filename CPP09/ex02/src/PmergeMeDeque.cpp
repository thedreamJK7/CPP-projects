#include "../includes/PmergeMeDeque.hpp"

PmergeMeDeque::PmergeMeDeque(const char* argv[]): _leftover(-1) {
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

PmergeMeDeque::~PmergeMeDeque() { };

void PmergeMeDeque::insertionSort() {
	if (_nums.size() == 1)
	{
		_mainChain.push_back(_nums[0]);
		return ;
	} else {
		makePair(); // Step 1
		buildMainChain(); // Step 3
	}
}

/* Step 1: making a pair in descending order */

void PmergeMeDeque::makePair(void) {
	iterator	it = _nums.begin();
	iterator	pairEnd;

	if (_nums.size() % 2 == 1)
	{
		pairEnd = --_nums.end();
		_leftover = *pairEnd;
	} else
		pairEnd = _nums.end();
	while (it != pairEnd)
	{
		iterator	first = it++;
		if (*first < *it)
			std::swap(*first, *it);
		_pairs.push_back(std::make_pair(*first, *(it++)));
	}
}

/* Step 2: Merge sort the pairs according to the first(biggest) value */
void PmergeMeDeque::merge(iteratorP begin, iteratorP mid, iteratorP end) {
	// 2 sub container using range constructor
	deqP firstHalf(begin, mid);
	deqP secondHalf(mid, end);

	// iterators for sub containers
	iteratorP firstIt = firstHalf.begin();
	iteratorP secondIt = secondHalf.begin();
	iteratorP it = begin;
	while (firstIt != firstHalf.end() && secondIt != secondHalf.end()) {
		if (firstIt->first <= secondIt->first)
			*it = *firstIt++;
		else
			*it = *secondIt++;
		it++;
	}
	while (firstIt != firstHalf.end())
		*it++ = *firstIt++;
	while (secondIt != secondHalf.end())
		*it++ = *secondIt++;
}

void PmergeMeDeque::mergeSort(iteratorP begin, iteratorP end) {
	if (std::distance(begin, end) > 1) {
		iteratorP mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		mergeSort(begin, mid);
		mergeSort(mid, end);
		merge(begin, mid, end);
	}
}

/* STEP 3: Set the sorted sequence */
void PmergeMeDeque::buildMainChain() {

	mergeSort(_pairs.begin(), _pairs.end());

	iteratorP it = _pairs.begin();
	while (it != _pairs.end()) {
		_mainChain.push_back(it->first);
		_unsorted.push_back(it->second);
		it++;
	}
}

/* STEP 4: merge insertion */



