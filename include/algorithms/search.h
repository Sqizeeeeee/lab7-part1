#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

// Последовательный поиск с барьером (точно по псевдокоду)
int sequential_search(std::vector<int>& arr, int K);

// Бинарный поиск 
int binary_search(const std::vector<int>& arr, int K);

#endif