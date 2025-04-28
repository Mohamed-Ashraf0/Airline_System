#ifndef PASSENGER_SERIALIZER_HPP
#define PASSENGER_SERIALIZER_HPP

#include "json.hpp"
#include "Entities/Pilot.hpp"

class pilotJsonSerializer
{
public:
    static nlohmann::json serialize(const Pilot &pilot);
    static Pilot deserialize(const nlohmann::json &j);
};

#endif 