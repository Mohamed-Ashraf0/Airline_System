#ifndef PASSENGER_SERIALIZER_HPP
#define PASSENGER_SERIALIZER_HPP

#include "json.hpp"
#include "Entities/Flight_attendants.hpp"

class flightagentJsonSerializer
{
public:
    static nlohmann::json serialize(const FlightAttendant &flight_attendant);
    static FlightAttendant deserialize(const nlohmann::json &j);
};

#endif 