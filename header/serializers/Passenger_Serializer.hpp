#ifndef PASSENGER_SERIALIZER_HPP
#define PASSENGER_SERIALIZER_HPP

#include "json.hpp"
#include "Entities/Passenger.hpp"

class passengerJsonSerializer
{
public:
    static nlohmann::json serialize(const Passenger &passenger);
    static Passenger deserialize(const nlohmann::json &j);
};

#endif 