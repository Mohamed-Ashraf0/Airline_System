#ifndef MAINTENANCE_SERIALIZER_HPP
#define MAINTENANCE_SERIALIZER_HPP

#include "nlohmann/json.hpp"
#include "Entities/Maintenance.hpp"

class maintenanceJsonSerializer
{
public:
    static nlohmann::json serialize(const Maintenance &maintenance);
    static Maintenance deserialize(const nlohmann::json &j);
};

#endif 