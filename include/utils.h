#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <chrono>

// Структура для измерения времени
struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    
    void start() {
        start_time = std::chrono::high_resolution_clock::now();
    }
    
    long long stop() {
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
    }
};

// Структура для точки
struct Point {
    double x;
    double y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// Функции генерации тестовых данных
std::vector<int> generate_random_array(int size);
std::vector<int> generate_sorted_array(int size);
std::vector<int> generate_reversed_array(int size);
std::vector<Point> generate_random_points(int count);

#endif