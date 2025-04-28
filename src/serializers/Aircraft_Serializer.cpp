#include "serializers/Aircraft_Serializer.hpp"

nlohmann::json aircraftJsonSerializer::serialize(const Aircraft &aircraft)
{
    nlohmann::json j({{"Type", aircraft.Type},
                      {"seatCount", aircraft.seatCount},
                      {"Maintenance_id", aircraft.Maintenance_id}});
    return j;
}

Aircraft aircraftJsonSerializer::deserialize(const nlohmann::json &j)
{
    Aircraft aircraft;
    j.at("id").get_to(aircraft.id);
    j.at("Type").get_to(aircraft.Type);
    j.at("seatCount").get_to(aircraft.seatCount);
    j.at("Maintenance_id").get_to(aircraft.Maintenance_id);
    return aircraft;
}