#pragma once

#include <cstdint>

using int64 = std::int64_t;
using Timestamp = int64;

struct Coordinate {
    double longitude;
    double latitude;
};

enum class PaymentType : std::int8_t {
    CreditCard = 1,
    Cash = 2,
    NoCharge = 3,
    Dispute = 4,
    Unknown = 5,
    Voided = 6
};