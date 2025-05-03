#ifndef FLIGHT_SERIALIZER_HPP
#define FLIGHT_SERIALIZER_HPP

#include "nlohmann/json.hpp"
#include "Entities/Flight.hpp"

class flightJsonSerializer
{
public:
    static nlohmann::json serialize(const Flight &flight);
    static Flight deserialize(const nlohmann::json &j);
};

#endif 