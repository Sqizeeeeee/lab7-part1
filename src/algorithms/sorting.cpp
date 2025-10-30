#include "algorithms/sorting.h"
#include <vector>

// Сортировка выбором
void selection_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // Обмен A[i] и A[min]
        std::swap(arr[i], arr[min]);
    }
}

// Пузырьковая сортировка
void bubble_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j + 1] < arr[j]) {
                // Обмен A[j] и A[j + 1]
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}