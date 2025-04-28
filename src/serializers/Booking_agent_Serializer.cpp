#include "serializers/Booking_agent_Serializer.hpp"

nlohmann::json bookingagentJsonSerializer::serialize(const BookingAgent &booking_agent)
{
    nlohmann::json j({{"username", booking_agent.username},
                      {"password", booking_agent.password}});
    return j;
}

BookingAgent bookingagentJsonSerializer::deserialize(const nlohmann::json &j)
{
    BookingAgent booking_agent;
    j.at("id").get_to(booking_agent.id);
    j.at("username").get_to(booking_agent.username);
    j.at("password").get_to(booking_agent.password);
    return booking_agent;
}