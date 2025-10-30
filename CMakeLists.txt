cmake_minimum_required(VERSION 3.10)
project(algorithms_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем папки с исходниками
include_directories(include)

# Основная программа
add_executable(main 
    src/main.cpp
    src/algorithms/sorting.cpp
    src/algorithms/search.cpp
    src/algorithms/geometry.cpp
    src/utils.cpp
    src/csv_writer.cpp
)

# Тесты производительности
add_executable(performance_tests 
    tests/performance_tests.cpp
    src/algorithms/sorting.cpp
    src/algorithms/search.cpp
    src/algorithms/geometry.cpp
    src/utils.cpp
    src/csv_writer.cpp
)

# Тесты алгоритмов
add_executable(unit_tests 
    tests/unit_tests.cpp
    src/algorithms/sorting.cpp
    src/algorithms/search.cpp
    src/algorithms/geometry.cpp
    src/utils.cpp
    src/csv_writer.cpp
)