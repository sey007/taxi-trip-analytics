#include "TimeUtilities.h"
#include <ctime>

namespace {

    inline int to2(const char* p) {
        return (p[0] - '0') * 10 + (p[1] - '0');
    }

    inline int to4(const char* p) {
        return (p[0] - '0') * 1000 +
            (p[1] - '0') * 100 +
            (p[2] - '0') * 10 +
            (p[3] - '0');
    }

}

namespace TimeUtilities {

    std::int64_t parseTimestamp(const char* ts) {
        std::tm tm{};
        tm.tm_year = to4(ts) - 1900;
        tm.tm_mon = to2(ts + 5) - 1;
        tm.tm_mday = to2(ts + 8);
        tm.tm_hour = to2(ts + 11);
        tm.tm_min = to2(ts + 14);
        tm.tm_sec = to2(ts + 17);
        tm.tm_isdst = -1;

        return static_cast<std::int64_t>(std::mktime(&tm));
    }

    int hourOfDay(std::int64_t timestamp) {
        std::time_t t = static_cast<std::time_t>(timestamp);
        std::tm tm{};
        localtime_s(&tm, &t);
        return tm.tm_hour;
    }

}


