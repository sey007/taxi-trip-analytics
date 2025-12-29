#include "Trip.h"

#include <cmath>

Trip::Trip(
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
)
    : vendor_id(vendor_id_),
    pickup_time(pickup_time_),
    dropoff_time(dropoff_time_),
    passenger_count(passenger_count_),
    trip_distance(trip_distance_),
    pickup_longitude(pickup_longitude_),
    pickup_latitude(pickup_latitude_),
    dropoff_longitude(dropoff_longitude_),
    dropoff_latitude(dropoff_latitude_),
    fare_amount(fare_amount_),
    tip_amount(tip_amount_),
    total_amount(total_amount_)
{
}


double Trip::durationMinutes() const {
    if (dropoff_time <= pickup_time) return 0.0;
    return static_cast<double>(dropoff_time - pickup_time) / 60.0;
}

double Trip::averageSpeedMph() const {
    double hours = durationMinutes() / 60.0;
    if (hours <= 0.0) return 0.0;
    return trip_distance / hours;
}