#ifndef PMERGEME_T
#define PMERGEME_T

#include "PmergeMe.hpp"

template <typename Container>
void PmergeMe<Container>::insertionSort() {
	if (_nums.size() == 1)
	{
		_mainChain.push_back(_nums[0]);
		return ;
	} else {
		makePair(); // Step 1
		buildMainChain(); // Step 3
		binaryInsert(); // Step 4
	}
}

/* Step 1: making a pair in descending order */
template <typename Container>
void PmergeMe<Container>::makePair(void) {
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
template <typename Container> 
void PmergeMe<Container>::merge(PairVecIt begin, PairVecIt mid, PairVecIt end) {
	// 2 sub container using range constructor
	PairVec firstHalf(begin, mid);
	PairVec secondHalf(mid, end);

	// iterators for sub containers
	PairVecIt firstIt = firstHalf.begin();
	PairVecIt secondIt = secondHalf.begin();
	PairVecIt it = begin;
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

template <typename Container>
void PmergeMe<Container>::mergeSort(PairVecIt begin, PairVecIt end) {
	if (std::distance(begin, end) > 1) {
		PairVecIt mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		mergeSort(begin, mid);
		mergeSort(mid, end);
		merge(begin, mid, end);
	}
}


template <typename Container>/* STEP 3: Set the sorted sequence */
void PmergeMe<Container>::buildMainChain() {

	mergeSort(_pairs.begin(), _pairs.end());

	PairVecIt it = _pairs.begin();
	while (it != _pairs.end()) {
		_mainChain.push_back(it->first);
		it++;
	}
}

/* STEP 4: merge insertion */
template <typename Container>
void PmergeMe<Container>::binaryInsert() {
	// b1 <= a1, insert at front without binary search
	_mainChain.insert(_mainChain.begin(), _pairs[0].second);
	std::vector<int> jacobSequence = jacobsthalSeq(_pairs.size());

	for (iterator it = jacobSequence.begin(); jacobSequence.end() != it; it++) {
		int partner = _pairs[*it - 1].second;
		iterator search_end = std::lower_bound(_mainChain.begin(), _mainChain.end(), _pairs[*it - 1].first);
		iterator insert_pos = std::lower_bound(_mainChain.begin(), search_end, partner);
		_mainChain.insert(insert_pos, partner);
	}
	if (_leftover != -1)
	{
		iterator insert_left = std::lower_bound(_mainChain.begin(), _mainChain.end(), _leftover);
		_mainChain.insert(insert_left, _leftover);
	}
}

#endif
