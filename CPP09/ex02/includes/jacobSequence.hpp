#ifndef JACOBSEQUENCE_HPP
#define JACOBSEQUENCE_HPP

#include <vector>

const int JACOBSTHAL[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731};
std::vector<int> jacobsthalSeq(std::size_t pendingSize);

#endif