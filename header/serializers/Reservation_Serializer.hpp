#ifndef RESERVATION_SERIALIZER_HPP
#define RESERVATION_SERIALIZER_HPP

#include "nlohmann/json.hpp"
#include "Entities/Reservation.hpp"

class reservationJsonSerializer
{
public:
    static nlohmann::json serialize(const Reservation &reservation);
    static Reservation deserialize(const nlohmann::json &j);
};

#endif 