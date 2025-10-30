#ifndef SORTING_H
#define SORTING_H

#include <vector>

// Сортировка выбором (точно по псевдокоду)
void selection_sort(std::vector<int>& arr);

// Пузырьковая сортировка (точно по псевдокоду)  
void bubble_sort(std::vector<int>& arr);

// Сортировка слиянием (точно по псевдокоду)
void merge_sort(std::vector<int>& arr);
void merge(const std::vector<int>& B, const std::vector<int>& C, std::vector<int>& A);

#endif