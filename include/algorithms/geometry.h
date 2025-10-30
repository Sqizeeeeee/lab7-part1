#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include "utils.h"

// Поиск пары ближайших точек методом грубой силы (точно по псевдокоду)
std::pair<int, int> brute_force_closest_points(const std::vector<Point>& P);

// Вспомогательная функция для вычисления расстояния
double calculate_distance(const Point& p1, const Point& p2);

#endif