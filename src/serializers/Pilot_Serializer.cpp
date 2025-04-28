#include "serializers/Pilot_Serializer.hpp"

nlohmann::json pilotJsonSerializer::serialize(const Pilot &pilot)
{
    nlohmann::json j({{"name", pilot.name},
                      {"flightIds", pilot.flightIds}});
    return j;
}

Pilot pilotJsonSerializer::deserialize(const nlohmann::json &j)
{
    Pilot pilot;
    j.at("id").get_to(pilot.id);
    j.at("name").get_to(pilot.name);
    j.at("flightIds").get_to(pilot.flightIds);
    return pilot;
}