#ifndef BOOKING_AGENT_HANDLER_HPP
#define BOOKING_AGENT_HANDLER_HPP

#include <memory>
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"
#include "Entities/Booking_agent.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Booking_agent_Serializer.hpp"
#include "Input_Handler.hpp"
#include "bcrypt.h"

#define REMOVE_ADD_OPTION false

class bookingagenthandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;

public:
    bookingagenthandler();

    BookingAgent login(const std::string &username, const std::string &password);
    void addBookingAgent(BookingAgent &bookingAgent);
    BookingAgent chooseBookingAgent(bool allowAddOption = true);
    void updateBookingAgent( BookingAgent &bookingAgent);
    void deleteBookingAgent(const std::string &bookingAgentId);
    void viewAllBookingAgents();
};

#endif