#ifndef PASSENGER_SERIALIZER_HPP
#define PASSENGER_SERIALIZER_HPP

#include "json.hpp"
#include "Entities/Reservation.hpp"

class reservationJsonSerializer
{
public:
    static nlohmann::json serialize(const Reservation &reservation);
    static Reservation deserialize(const nlohmann::json &j);
};

#endif 