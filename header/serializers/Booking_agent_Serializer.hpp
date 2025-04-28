#ifndef PASSENGER_SERIALIZER_HPP
#define PASSENGER_SERIALIZER_HPP

#include "json.hpp"
#include "Entities/Booking_agent.hpp"

class bookingagentJsonSerializer
{
public:
    static nlohmann::json serialize(const BookingAgent &booking_agent);
    static BookingAgent deserialize(const nlohmann::json &j);
};

#endif 