#include "serializers/Boarding_Serializer.hpp"

nlohmann::json boardingJsonSerializer::serialize(const Boarding &boarding)
{
    nlohmann::json j({{"passengerId", boarding.passengerId},
                      {"flightId", boarding.flightId},
                      {"reservationId", boarding.reservationId}});
    return j;
}

Boarding boardingJsonSerializer::deserialize(const nlohmann::json &j)
{
    Boarding boarding;
    j.at("passengerId").get_to(boarding.passengerId);
    j.at("flightId").get_to(boarding.flightId);
    j.at("reservationId").get_to(boarding.reservationId);
    return boarding;
}