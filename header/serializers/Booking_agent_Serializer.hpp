#ifndef BOOKING_AGENT_SERIALIZER_HPP
#define BOOKING_AGENT_SERIALIZER_HPP

#include "nlohmann/json.hpp"
#include "Entities/Booking_agent.hpp"

class bookingagentJsonSerializer
{
public:
    static nlohmann::json serialize(const BookingAgent &booking_agent);
    static BookingAgent deserialize(const nlohmann::json &j);
};

#endif 