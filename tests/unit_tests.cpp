#include <iostream>
#include <vector>
#include <cassert>
#include "algorithms/sorting.h"
#include "algorithms/search.h"
#include "algorithms/geometry.h"

void test_selection_sort() {
    std::cout << "Тестирование Selection Sort..." << std::endl;
    
    std::vector<int> arr = {5, 2, 8, 1, 9, 3};
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};
    
    selection_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Произвольный массив" << std::endl;
    
    // Уже отсортированный
    arr = {1, 2, 3, 4, 5};
    expected = {1, 2, 3, 4, 5};
    selection_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Отсортированный массив" << std::endl;
    
    // Обратный порядок
    arr = {5, 4, 3, 2, 1};
    expected = {1, 2, 3, 4, 5};
    selection_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Обратный порядок" << std::endl;
}

void test_bubble_sort() {
    std::cout << "Тестирование Bubble Sort..." << std::endl;
    
    std::vector<int> arr = {5, 2, 8, 1, 9, 3};
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};
    
    bubble_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Произвольный массив" << std::endl;
    
    // Один элемент
    arr = {42};
    expected = {42};
    bubble_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Один элемент" << std::endl;
}

void test_merge_sort() {
    std::cout << "Тестирование Merge Sort..." << std::endl;
    
    std::vector<int> arr = {5, 2, 8, 1, 9, 3};
    std::vector<int> expected = {1, 2, 3, 5, 8, 9};
    
    merge_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Произвольный массив" << std::endl;
    
    // Пустой массив
    arr = {};
    expected = {};
    merge_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Пустой массив" << std::endl;
    
    // Два элемента
    arr = {2, 1};
    expected = {1, 2};
    merge_sort(arr);
    assert(arr == expected);
    std::cout << "  ✓ Два элемента" << std::endl;
}

void test_sequential_search() {
    std::cout << "Тестирование Sequential Search..." << std::endl;
    
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    
    // Элемент найден
    int pos = sequential_search(arr, 7);
    assert(pos == 3);
    std::cout << "  ✓ Элемент найден" << std::endl;
    
    // Элемент не найден
    pos = sequential_search(arr, 6);
    assert(pos == -1);
    std::cout << "  ✓ Элемент не найден" << std::endl;
    
    // Первый элемент
    pos = sequential_search(arr, 1);
    assert(pos == 0);
    std::cout << "  ✓ Первый элемент" << std::endl;
}

void test_binary_search() {
    std::cout << "Тестирование Binary Search..." << std::endl;
    
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    
    // Элемент найден
    int pos = binary_search(arr, 7);
    assert(pos == 3);
    std::cout << "  ✓ Элемент найден" << std::endl;
    
    // Элемент не найден
    pos = binary_search(arr, 6);
    assert(pos == -1);
    std::cout << "  ✓ Элемент не найден" << std::endl;
    
    // Граничные случаи
    pos = binary_search(arr, 1);
    assert(pos == 0);
    std::cout << "  ✓ Первый элемент" << std::endl;
    
    pos = binary_search(arr, 11);
    assert(pos == 5);
    std::cout << "  ✓ Последний элемент" << std::endl;
}

void test_brute_force_closest_points() {
    std::cout << "Тестирование Brute Force Closest Points..." << std::endl;
    
    // Точки образуют квадрат
    std::vector<Point> points = {
        Point(0, 0), Point(1, 0), Point(0, 1), Point(1, 1)
    };
    
    auto result = brute_force_closest_points(points);
    double distance = calculate_distance(points[result.first], points[result.second]);
    
    // Ближайшие точки должны быть на расстоянии 1.0
    assert(distance == 1.0);
    std::cout << "  ✓ Квадрат точек" << std::endl;
    
    // Точки с явными ближайшими
    points = {
        Point(0, 0), Point(10, 10), Point(0.1, 0.1), Point(5, 5)
    };
    
    result = brute_force_closest_points(points);
    distance = calculate_distance(points[result.first], points[result.second]);
    
    // Ближайшие должны быть (0,0) и (0.1,0.1)
    assert(distance < 0.2);
    std::cout << "  ✓ Явные ближайшие точки" << std::endl;
}

void run_all_tests() {
    std::cout << "=== ЗАПУСК UNIT-ТЕСТОВ ===" << std::endl;
    
    test_selection_sort();
    test_bubble_sort();
    test_merge_sort();
    test_sequential_search();
    test_binary_search();
    test_brute_force_closest_points();
    
    std::cout << "=== ВСЕ ТЕСТЫ ПРОЙДЕНЫ УСПЕШНО! ===" << std::endl;
}

int main() {
    run_all_tests();
    return 0;
}