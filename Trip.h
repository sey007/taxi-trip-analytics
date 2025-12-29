#pragma once

#include <cstdint>

struct Trip {
    // Data
    int vendor_id;
    std::int64_t pickup_time;
    std::int64_t dropoff_time;
    int passenger_count;
    double trip_distance;
    double pickup_longitude;
    double pickup_latitude;
    double dropoff_longitude;
    double dropoff_latitude;
    double fare_amount;
    double tip_amount;
    double total_amount;

    // Constructor
    Trip(
        int vendor_id_,
        std::int64_t pickup_time_,
        std::int64_t dropoff_time_,
        int passenger_count_,
        double trip_distance_,
        double pickup_longitude_,
        double pickup_latitude_,
        double dropoff_longitude_,
        double dropoff_latitude_,
        double fare_amount_,
        double tip_amount_,
        double total_amount_
    );

    // Derived quantities
    double durationMinutes() const;
    double averageSpeedMph() const;
};
