#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <string>
#include <vector>
#include <fstream>

struct CSVWriter {
    std::ofstream file;
    
    bool open(const std::string& filename);
    void write_header(const std::vector<std::string>& columns);
    void write_row(const std::vector<std::string>& values);
    void close();
};

#endif