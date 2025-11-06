#include "algorithms/search.h"
#include <vector>
#include <algorithm> // для std::sort в бинарном поиске

// Последовательный поиск с барьером
int sequential_search(std::vector<int>& arr, int K) {
    int n = arr.size();

    arr.push_back(K);
    int i = 0;
    
    while (arr[i] != K) {
        i = i + 1;
    }
    

    arr.pop_back();
    
    if (i < n) {
        return i;
    } else {
        return -1;
    }
}

// Бинарный поиск
int binary_search(const std::vector<int>& arr, int K) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == K) {
            return mid;
        } else if (arr[mid] < K) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}