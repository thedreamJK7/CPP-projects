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
		binaryInsert(); // Step 4
	}
}

/* Step 1: making a pair in descending order */

void PmergeMeDeque::makePair(void) {
	iteratorD	it = _nums.begin();
	iteratorD	pairEnd;

	if (_nums.size() % 2 == 1)
	{
		pairEnd = --_nums.end();
		_leftover = *pairEnd;
	} else
		pairEnd = _nums.end();
	while (it != pairEnd)
	{
		iteratorD	first = it++;
		if (*first < *it)
			std::swap(*first, *it);
		_pairs.push_back(std::make_pair(*first, *(it++)));
	}
}

/* Step 2: Merge sort the pairs according to the first(biggest) value */
void PmergeMeDeque::merge(iteratorPair begin, iteratorPair mid, iteratorPair end) {
	// 2 sub container using range constructor
	deqP firstHalf(begin, mid);
	deqP secondHalf(mid, end);

	// iterators for sub containers
	iteratorPair firstIt = firstHalf.begin();
	iteratorPair secondIt = secondHalf.begin();
	iteratorPair it = begin;
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

void PmergeMeDeque::mergeSort(iteratorPair begin, iteratorPair end) {
	if (std::distance(begin, end) > 1) {
		iteratorPair mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		mergeSort(begin, mid);
		mergeSort(mid, end);
		merge(begin, mid, end);
	}
}

/* STEP 3: Set the sorted sequence */
void PmergeMeDeque::buildMainChain() {

	mergeSort(_pairs.begin(), _pairs.end());

	iteratorPair it = _pairs.begin();
	while (it != _pairs.end()) {
		_mainChain.push_back(it->first);
		it++;
	}
}

/* STEP 4: merge insertion */
static const int JACOBSTHAL[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731};

static std::deque<int> jacobsthalSeq(size_t pendingSize) {
	std::deque<int> out;
	std::deque<int> jacob;
	if (pendingSize == 0) return out;
	
	// Copy terms < pendingSize
	for (size_t i = 0; i < 12; i++) {
		if (JACOBSTHAL[i] >= static_cast<int>(pendingSize)) break;
		jacob.push_back(JACOBSTHAL[i]);
	}

	// expanding each into descending runs + tail
	size_t last = 1;
	for (size_t i = 0; i < jacob.size(); i++)
	{
		out.push_back(jacob[i]);
		for (size_t j = jacob[i] - 1; last < j; --j)
			out.push_back(j);
		last = jacob[i];
	}
	for (size_t j = pendingSize; j > last; j--)
		out.push_back(j);
	return (out);
}

// iterator insert_pos = _mainChain.begin();
// while (insert_pos != _mainChain.end() && *insert_pos < partner)
// 	insert_pos++;

void PmergeMeDeque::binaryInsert() {
	// b1 <= a1, insert at front without binary search
	_mainChain.insert(_mainChain.begin(), _pairs[0].second);
	std::deque<int> jacobSequence = jacobsthalSeq(_pairs.size());

	for (iteratorD it = jacobSequence.begin(); jacobSequence.end() != it; it++) {
		int partner = _pairs[*it - 1].second;
		iteratorD search_end = std::lower_bound(_mainChain.begin(), _mainChain.end(), _pairs[*it - 1].first);
		iteratorD insert_pos = std::lower_bound(_mainChain.begin(), search_end, partner);
		_mainChain.insert(insert_pos, partner);
	}
	if (_leftover != -1)
	{
		iteratorD insert_lef = std::lower_bound(_mainChain.begin(), _mainChain.end(), _leftover);
		_mainChain.insert(insert_lef, _leftover);
	}
}
