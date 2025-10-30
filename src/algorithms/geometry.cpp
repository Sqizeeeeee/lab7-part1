#include "algorithms/geometry.h"
#include <vector>
#include <cmath>
#include <limits>

// Вычисление расстояния между двумя точками
double calculate_distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Поиск пары ближайших точек методом грубой силы
std::pair<int, int> brute_force_closest_points(const std::vector<Point>& P) {
    int n = P.size();
    double dmin = std::numeric_limits<double>::max();
    int index1 = -1;
    int index2 = -1;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = calculate_distance(P[i], P[j]);
            if (d < dmin) {
                dmin = d;
                index1 = i;
                index2 = j;
            }
        }
    }
    
    return std::make_pair(index1, index2);
}