#include "serializers/Flight_attendants_Serializer.hpp"

nlohmann::json flightagentJsonSerializer::serialize(const FlightAttendant &flight_attendant)
{
    nlohmann::json j({{"name", flight_attendant.name},
                      {"flightIds", flight_attendant.flightIds}});
    return j;
}

FlightAttendant flightagentJsonSerializer::deserialize(const nlohmann::json &j)
{
    FlightAttendant flight_attendant;
    j.at("id").get_to(flight_attendant.id);
    j.at("name").get_to(flight_attendant.name);
    j.at("flightIds").get_to(flight_attendant.flightIds);
    return flight_attendant;
}