#include <iostream>
#include <vector>
#include <string>
#include "algorithms/sorting.h"
#include "algorithms/search.h"
#include "algorithms/geometry.h"
#include "utils.h"
#include "csv_writer.h"

void test_sorting_algorithms() {
    std::cout << "ТЕСТИРОВАНИЕ АЛГОРИТМОВ СОРТИРОВКИ..." << std::endl;
    
    CSVWriter csv;
    if (!csv.open("../data/sorting_results.csv")) return;
    
    csv.write_header({"algorithm", "data_size", "case_type", "time_micros"});
    
    std::vector<int> sizes = {100, 500, 1000, 5000}; // Можно увеличить для реальных тестов
    
    for (int size : sizes) {
        std::cout << "Размер массива: " << size << std::endl;
        
        // Тестируем разные случаи
        std::vector<std::string> cases = {"random", "sorted", "reversed"};
        
        for (const auto& case_type : cases) {
            std::vector<int> arr;
            
            if (case_type == "random") arr = generate_random_array(size);
            else if (case_type == "sorted") arr = generate_sorted_array(size);
            else if (case_type == "reversed") arr = generate_reversed_array(size);
            
            // Тестируем каждый алгоритм
            std::vector<std::string> algorithms = {"selection", "bubble", "merge"};
            
            for (const auto& algo : algorithms) {
                std::vector<int> test_arr = arr;
                Timer timer;
                
                timer.start();
                if (algo == "selection") selection_sort(test_arr);
                else if (algo == "bubble") bubble_sort(test_arr);
                else if (algo == "merge") merge_sort(test_arr);
                long long time = timer.stop();
                
                csv.write_row({algo, std::to_string(size), case_type, std::to_string(time)});
            }
        }
    }
    
    csv.close();
    std::cout << "Результаты сохранены в data/sorting_results.csv" << std::endl;
}

void test_search_algorithms() {
    std::cout << "\nТЕСТИРОВАНИЕ АЛГОРИТМОВ ПОИСКА..." << std::endl;
    
    CSVWriter csv;
    if (!csv.open("../data/search_results.csv")) return;
    
    csv.write_header({"algorithm", "data_size", "case_type", "time_micros", "found_position"});
    
    std::vector<int> sizes = {1000, 5000, 10000, 50000};
    
    for (int size : sizes) {
        std::cout << "Размер массива: " << size << std::endl;
        
        std::vector<int> arr = generate_sorted_array(size);
        
        // Тестируем разные случаи поиска
        std::vector<int> keys = {0, size/2, size-1, size+1}; // лучший, средний, худший, не найден
        
        for (int key : keys) {
            std::string case_type;
            if (key == 0) case_type = "best";
            else if (key == size/2) case_type = "average";
            else if (key == size-1) case_type = "worst";
            else case_type = "not_found";
            
            // Sequential search
            std::vector<int> arr_seq = arr;
            Timer timer;
            timer.start();
            int pos_seq = sequential_search(arr_seq, key);
            long long time_seq = timer.stop();
            csv.write_row({"sequential", std::to_string(size), case_type, 
                          std::to_string(time_seq), std::to_string(pos_seq)});
            
            // Binary search
            timer.start();
            int pos_bin = binary_search(arr, key);
            long long time_bin = timer.stop();
            csv.write_row({"binary", std::to_string(size), case_type, 
                          std::to_string(time_bin), std::to_string(pos_bin)});
        }
    }
    
    csv.close();
    std::cout << "Результаты сохранены в data/search_results.csv" << std::endl;
}

void test_closest_points() {
    std::cout << "\nТЕСТИРОВАНИЕ ПОИСКА БЛИЖАЙШИХ ТОЧЕК..." << std::endl;
    
    CSVWriter csv;
    if (!csv.open("../data/geometry_results.csv")) return;
    
    csv.write_header({"algorithm", "points_count", "time_micros", "distance"});
    
    std::vector<int> counts = {10, 50, 100, 500, 1000};
    
    for (int count : counts) {
        std::cout << "Количество точек: " << count << std::endl;
        
        std::vector<Point> points = generate_random_points(count);
        
        // Brute force
        Timer timer;
        timer.start();
        auto result = brute_force_closest_points(points);
        long long time = timer.stop();
        
        double distance = calculate_distance(points[result.first], points[result.second]);
        
        csv.write_row({"brute_force", std::to_string(count), 
                      std::to_string(time), std::to_string(distance)});
    }
    
    csv.close();
    std::cout << "Результаты сохранены в data/geometry_results.csv" << std::endl;
}

int main() {
    // Создаем папку data если её нет
    system("mkdir -p ../data");
    
    test_sorting_algorithms();
    test_search_algorithms();
    test_closest_points();
    
    std::cout << "\nВсе тесты завершены!" << std::endl;
    return 0;
}