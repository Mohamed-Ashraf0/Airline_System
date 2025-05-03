#include "serializers/Passenger_Serializer.hpp"

nlohmann::json passengerJsonSerializer::serialize(const Passenger &passenger)
{
    nlohmann::json j({{"username", passenger.username},
                      {"password", passenger.password},
                      {"Reservations_id", passenger.Reservations_id},
                      {"BoardingPasses_id", passenger.BoardingPasses_id},
                      {"PaymentMethod", passenger.PaymentMethod_id}});
    return j;
}

Passenger passengerJsonSerializer::deserialize(const nlohmann::json &j)
{
    Passenger passenger;
    j.at("id").get_to(passenger.id);
    j.at("username").get_to(passenger.username);
    j.at("password").get_to(passenger.password);
    j.at("Reservations_id").get_to(passenger.Reservations_id);
    j.at("BoardingPasses_id").get_to(passenger.BoardingPasses_id);
    j.at("PaymentMethod").get_to(passenger.PaymentMethod_id);
    return passenger;
}