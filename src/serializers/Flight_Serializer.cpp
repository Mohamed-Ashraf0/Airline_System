#include "serializers/Flight_Serializer.hpp"

nlohmann::json flightJsonSerializer::serialize(const Flight &flight)
{
    nlohmann::json j({{"Origin", flight.Origin},
                      {"Destination", flight.Destination},
                      {"Departure_Date_and_Time", flight.Departure_Date_and_Time},
                      {"Arrival_Date_and_Time", flight.Arrival_Date_and_Time},
                      {"Aircraft_id", flight.Aircraft_id},
                      {"BoardingGate", flight.BoardingGate},
                      {"Passengers_id", flight.Passengers_id},
                      {"status", flight.status},
                      {"cost", flight.cost},
                      {"seats", flight.seats},
                      {"seatCount", flight.seatCount},
                      {"availableSeats", flight.availableSeats}});
    return j;
}

Flight flightJsonSerializer::deserialize(const nlohmann::json &j)
{
    Flight flight;
    j.at("id").get_to(flight.id);
    j.at("Origin").get_to(flight.Origin);
    j.at("Destination").get_to(flight.Destination);
    j.at("Departure_Date_and_Time").get_to(flight.Departure_Date_and_Time);
    j.at("Arrival_Date_and_Time").get_to(flight.Arrival_Date_and_Time);
    j.at("Aircraft_id").get_to(flight.Aircraft_id);
    j.at("BoardingGate").get_to(flight.BoardingGate);
    j.at("Passengers_id").get_to(flight.Passengers_id);
    j.at("status").get_to(flight.status);
    j.at("cost").get_to(flight.cost);
    j.at("seats").get_to(flight.seats);
    j.at("seatCount").get_to(flight.seatCount);
    j.at("availableSeats").get_to(flight.availableSeats);
    return flight;
}