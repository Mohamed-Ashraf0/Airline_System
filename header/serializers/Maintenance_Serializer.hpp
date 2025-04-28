#ifndef PASSENGER_SERIALIZER_HPP
#define PASSENGER_SERIALIZER_HPP

#include "json.hpp"
#include "Entities/Maintenance.hpp"

class maintenanceJsonSerializer
{
public:
    static nlohmann::json serialize(const Maintenance &maintenance);
    static Maintenance deserialize(const nlohmann::json &j);
};

#endif 