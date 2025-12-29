#include "Analytics.h"
#include "TimeUtilities.h"

#include <vector>
#include <map>

namespace Analytics {

    double meanFare(const std::vector<Trip>& trips) {
        if (trips.empty()) return 0.0;

        double sum = 0.0;
        for (const auto& trip : trips) {
            sum += trip.fare_amount;
        }
        return sum / trips.size();
    }

    double meanTripDistance(const std::vector<Trip>& trips) {
        if (trips.empty()) return 0.0;

        double sum = 0.0;
        for (const auto& trip : trips) {
            sum += trip.trip_distance;
        }
        return sum / trips.size();
    }

    double averageSpeedMph(const std::vector<Trip>& trips) {
        if (trips.empty()) return 0.0;

        double total_distance = 0.0;
        double total_hours = 0.0;

        for (const auto& trip : trips) {
            double duration_hours = trip.durationMinutes() / 60.0;
            if (duration_hours > 0.0) {
                total_distance += trip.trip_distance;
                total_hours += duration_hours;
            }
        }

        if (total_hours <= 0.0) return 0.0;
        return total_distance / total_hours;
    }

    std::map<int, double> averageFareByHour(const std::vector<Trip>& trips) {
        std::map<int, double> fare_sum;
        std::map<int, int> count;

        for (const auto& trip : trips) {
            int hour = TimeUtilities::hourOfDay(trip.pickup_time);
            fare_sum[hour] += trip.fare_amount;
            count[hour] += 1;
        }

        std::map<int, double> result;
        for (const auto& [hour, sum] : fare_sum) {
            result[hour] = sum / count[hour];
        }

        return result;
    }

    std::map<int, double> tripCountByHour(const std::vector<Trip>& trips) {
        std::map<int, double> counts;

        for (const auto& trip : trips) {
            int hour = TimeUtilities::hourOfDay(trip.pickup_time);
            counts[hour] += 1.0;
        }

        return counts;
    }

    std::map<int, double> averageTipByPassengerCount(const std::vector<Trip>& trips) {
        std::map<int, double> tip_sum;
        std::map<int, int> count;

        for (const auto& trip : trips) {
            int p = trip.passenger_count;
            if (p <= 0) continue;

            tip_sum[p] += trip.tip_amount;
            count[p] += 1;
        }

        std::map<int, double> result;
        for (const auto& [p, sum] : tip_sum) {
            result[p] = sum / count[p];
        }

        return result;
    }

}
