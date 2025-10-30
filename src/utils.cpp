#include "utils.h"
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> generate_random_array(int size) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, size * 10);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dist(gen);
    }
    return arr;
}

std::vector<int> generate_sorted_array(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> generate_reversed_array(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

std::vector<Point> generate_random_points(int count) {
    std::vector<Point> points(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1000.0);
    
    for (int i = 0; i < count; i++) {
        points[i] = Point(dist(gen), dist(gen));
    }
    return points;
}