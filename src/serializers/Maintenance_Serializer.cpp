#include "serializers/Maintenance_Serializer.hpp"

nlohmann::json maintenanceJsonSerializer::serialize(const Maintenance &maintenance)
{
    nlohmann::json j({{"date", maintenance.date},
                      {"aircraftId", maintenance.aircraftId},
                      {"details", maintenance.details}});
    return j;
}

Maintenance maintenanceJsonSerializer::deserialize(const nlohmann::json &j)
{
    Maintenance maintenance;
    j.at("id").get_to(maintenance.id);
    j.at("date").get_to(maintenance.date);
    j.at("aircraftId").get_to(maintenance.aircraftId);
    j.at("details").get_to(maintenance.details);
    return maintenance;
}