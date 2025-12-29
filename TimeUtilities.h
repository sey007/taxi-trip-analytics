#pragma once
#include <cstdint>
#include <string>

namespace TimeUtilities {
    std::int64_t parseTimestamp(const char* ts);
    int hourOfDay(std::int64_t timestamp);
}
