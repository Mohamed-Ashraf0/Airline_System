#ifndef PILOT_SERIALIZER_HPP
#define PILOT_SERIALIZER_HPP

#include "nlohmann/json.hpp"
#include "Entities/Pilot.hpp"

class pilotJsonSerializer
{
public:
    static nlohmann::json serialize(const Pilot &pilot);
    static Pilot deserialize(const nlohmann::json &j);
};

#endif 