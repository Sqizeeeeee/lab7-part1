#include <iostream>
#include <vector>
#include "algorithms/sorting.h"
#include "algorithms/search.h"
#include "algorithms/geometry.h"
#include "utils.h"

void demonstrate_sorting() {
    std::cout << "=== ДЕМОНСТРАЦИЯ СОРТИРОВОК ===" << std::endl;
    
    std::vector<int> arr = {5, 2, 8, 1, 9, 3};
    std::vector<int> arr_copy = arr;
    
    std::cout << "Исходный массив: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;
    
    selection_sort(arr_copy);
    std::cout << "Selection sort: ";
    for (int x : arr_copy) std::cout << x << " ";
    std::cout << std::endl;
    
    arr_copy = arr;
    bubble_sort(arr_copy);
    std::cout << "Bubble sort: ";
    for (int x : arr_copy) std::cout << x << " ";
    std::cout << std::endl;
    
    arr_copy = arr;
    merge_sort(arr_copy);
    std::cout << "Merge sort: ";
    for (int x : arr_copy) std::cout << x << " ";
    std::cout << std::endl;
}

void demonstrate_search() {
    std::cout << "\n=== ДЕМОНСТРАЦИЯ ПОИСКА ===" << std::endl;
    
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    int key = 7;
    
    std::cout << "Массив: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\nКлюч: " << key << std::endl;
    
    std::vector<int> arr_seq = arr;
    int pos = sequential_search(arr_seq, key);
    std::cout << "Sequential search: позиция " << pos << std::endl;
    
    pos = binary_search(arr, key);
    std::cout << "Binary search: позиция " << pos << std::endl;
}

void demonstrate_geometry() {
    std::cout << "\n=== ДЕМОНСТРАЦИЯ БЛИЖАЙШИХ ТОЧЕК ===" << std::endl;
    
    std::vector<Point> points = {
        Point(1, 1), Point(2, 3), Point(5, 5), Point(7, 2), Point(4, 4)
    };
    
    auto result = brute_force_closest_points(points);
    std::cout << "Ближайшие точки: " << result.first << " и " << result.second << std::endl;
    std::cout << "Расстояние: " << calculate_distance(points[result.first], points[result.second]) << std::endl;
}

int main() {
    demonstrate_sorting();
    demonstrate_search();
    demonstrate_geometry();
    return 0;
}