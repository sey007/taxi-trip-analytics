#pragma once

#include "Trip.h"
#include <string>
#include <vector>

class CSVReader {
public:
    explicit CSVReader(const std::string& filename);

    std::vector<Trip> readAll();

private:
    std::string filename_;

    Trip parseRow(const std::vector<std::string>& tokens);
    std::vector<std::string> split(const std::string& line) const;
};
