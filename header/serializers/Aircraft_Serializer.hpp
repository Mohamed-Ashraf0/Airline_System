#ifndef PASSENGER_SERIALIZER_HPP
#define PASSENGER_SERIALIZER_HPP

#include "json.hpp"
#include "Entities/Aircraft.hpp"

class aircraftJsonSerializer
{
public:
    static nlohmann::json serialize(const Aircraft &aircraft);
    static Aircraft deserialize(const nlohmann::json &j);
};

#endif 