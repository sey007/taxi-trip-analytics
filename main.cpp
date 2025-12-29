#include <iostream>

#include "CSVReader.h"
#include "Analytics.h"

int main() {
    try {
        std::cout << "Loading NYC taxi trip data...\n";

        CSVReader reader("data/yellow_tripdata_2015-01.csv");
        auto trips = reader.readAll();

        std::cout << "Loaded " << trips.size() << " trips.\n";
        if (trips.empty()) {
            std::cout << "WARNING: No trips parsed. CSV format mismatch.\n";
        }


        std::cout << "Loaded " << trips.size() << " trips.\n\n";

        // Basic analytics
        std::cout << "Mean fare: $"
            << Analytics::meanFare(trips) << "\n";

        std::cout << "Mean trip distance: "
            << Analytics::meanTripDistance(trips) << " miles\n";

        std::cout << "Average speed: "
            << Analytics::averageSpeedMph(trips) << " mph\n\n";

        // Hourly statistics
        auto avgFareByHour = Analytics::averageFareByHour(trips);
        auto tripCountByHour = Analytics::tripCountByHour(trips);

        std::cout << "Average fare by pickup hour:\n";
        for (const auto& [hour, fare] : avgFareByHour) {
            std::cout << "  Hour " << hour
                << ": $" << fare
                << " (" << tripCountByHour[hour] << " trips)\n";
        }

        // Passenger behavior
        auto avgTipByPassengers = Analytics::averageTipByPassengerCount(trips);

        std::cout << "\nAverage tip by passenger count:\n";
        for (const auto& [p, tip] : avgTipByPassengers) {
            std::cout << "  " << p << " passengers: $" << tip << "\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    }

    return 0;




}
