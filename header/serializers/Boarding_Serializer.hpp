#ifndef BOARDING_SERIALIZER_HPP
#define BOARDING_SERIALIZER_HPP

#include "nlohmann/json.hpp"
#include "Entities/Boarding.hpp"

class boardingJsonSerializer
{
public:
    static nlohmann::json serialize(const Boarding &boarding);
    static Boarding deserialize(const nlohmann::json &j);
};

#endif 