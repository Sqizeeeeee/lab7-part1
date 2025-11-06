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

// Вспомогательная функция для слияния
void merge(const std::vector<int>& B, const std::vector<int>& C, std::vector<int>& A) {
    int i = 0, j = 0, k = 0;
    int p = B.size();
    int q = C.size();
    
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i = i + 1;
        } else {
            A[k] = C[j];
            j = j + 1;
        }
        k = k + 1;
    }
    
    if (i == p) {
        // Копировать C[j..q-1] в A[k..p+q-1]
        for (int idx = j; idx < q; idx++) {
            A[k] = C[idx];
            k = k + 1;
        }
    } else {
        // Копировать B[i..p-1] в A[k..p+q-1]
        for (int idx = i; idx < p; idx++) {
            A[k] = B[idx];
            k = k + 1;
        }
    }
}

// Сортировка слиянием
void merge_sort(std::vector<int>& arr) {
    int n = arr.size();
    if (n > 1) {
        std::vector<int> B(arr.begin(), arr.begin() + n/2);
        std::vector<int> C(arr.begin() + n/2, arr.end());
        
        merge_sort(B);
        merge_sort(C);
        merge(B, C, arr);
    }
}