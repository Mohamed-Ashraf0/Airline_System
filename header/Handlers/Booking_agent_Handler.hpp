#ifndef BOOKING_AGENT_HANDLER_HPP
#define BOOKING_AGENT_HANDLER_HPP

#include <memory>
#include <string>
#include "json.hpp"
#include "Entities/Booking_agent.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Booking_agent_Serializer.hpp"

class bookingagenthandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    bookingagenthandler();

    Passenger login(const std::string &username, const std::string &password);
    void addPassenger(const Passenger &passenger);
    void updatePassenger(const Passenger &passenger);
    void deletePassenger(const std::string &passengerId);
};

#endif