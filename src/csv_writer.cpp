#include "csv_writer.h"
#include <iostream>

bool CSVWriter::open(const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return false;
    }
    return true;
}

void CSVWriter::write_header(const std::vector<std::string>& columns) {
    for (size_t i = 0; i < columns.size(); i++) {
        file << columns[i];
        if (i < columns.size() - 1) file << ",";
    }
    file << "\n";
}

void CSVWriter::write_row(const std::vector<std::string>& values) {
    for (size_t i = 0; i < values.size(); i++) {
        file << values[i];
        if (i < values.size() - 1) file << ",";
    }
    file << "\n";
}

void CSVWriter::close() {
    if (file.is_open()) {
        file.close();
    }
}