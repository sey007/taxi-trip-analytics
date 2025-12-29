#pragma once

#include "Trip.h"
#include <vector>
#include <map>

namespace Analytics {

    double meanFare(const std::vector<Trip>& trips);
    double meanTripDistance(const std::vector<Trip>& trips);

    double averageSpeedMph(const std::vector<Trip>& trips);

    std::map<int, double> averageFareByHour(const std::vector<Trip>& trips);
    std::map<int, double> tripCountByHour(const std::vector<Trip>& trips);

    std::map<int, double> averageTipByPassengerCount(const std::vector<Trip>& trips);
}
