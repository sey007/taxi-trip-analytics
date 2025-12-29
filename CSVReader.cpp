#include "CSVReader.h"
#include "TimeUtilities.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

CSVReader::CSVReader(const std::string& filename)
    : filename_(filename) {
}

static inline const char* nextField(const char*& p) {
    const char* start = p;
    while (*p && *p != ',') ++p;
    if (*p == ',') ++p;
    return start;
}

std::vector<Trip> CSVReader::readAll() {
    std::ifstream file(filename_);
    if (!file) {
        throw std::runtime_error("Failed to open file");
    }

    std::vector<Trip> trips;
    trips.reserve(13'000'000); // avoid reallocations

    std::string line;
    std::getline(file, line); // skip header

    std::size_t lineCount = 0;

    while (std::getline(file, line)) {
        const char* p = line.c_str();

        try {
            int vendor_id = std::atoi(nextField(p));
            auto pickup = TimeUtilities::parseTimestamp(nextField(p));
            auto dropoff = TimeUtilities::parseTimestamp(nextField(p));
            int passengers = std::atoi(nextField(p));
            double distance = std::atof(nextField(p));
            double pick_lon = std::atof(nextField(p));
            double pick_lat = std::atof(nextField(p));

            nextField(p); // RateCodeID
            nextField(p); // store_and_fwd_flag

            double drop_lon = std::atof(nextField(p));
            double drop_lat = std::atof(nextField(p));

            nextField(p); // payment_type

            double fare = std::atof(nextField(p));
            nextField(p); // extra
            nextField(p); // mta_tax
            nextField(p); // improvement_surcharge
            double tip = std::atof(nextField(p));
            nextField(p); // tolls
            double total = std::atof(nextField(p));

            trips.emplace_back(
                vendor_id,
                pickup,
                dropoff,
                passengers,
                distance,
                pick_lon,
                pick_lat,
                drop_lon,
                drop_lat,
                fare,
                tip,
                total
            );
        }
        catch (...) {
            continue;
        }

#ifndef NDEBUG
        if (++lineCount % 100000 == 0) {
            std::cout << "Parsed " << lineCount << " lines...\n";
        }
#endif
    }

    return trips;
}
