#ifndef BOOKING_AGENT_HPP
#define BOOKING_AGENT_HPP

#include <iostream>
#include <string>
#include "Entities/Entity.hpp"

class BookingAgent {
private:
    std::string id;
    std::string username;
    std::string password;

public:

    BookingAgent() = default;
    BookingAgent(const std::string &username, const std::string &password);

    const std::string &getId() const;
    const std::string &getUsername() const;
    const std::string &getPassword() const;

    void setId(const std::string &id);
    void setUsername(const std::string &username);
    void setPassword(const std::string &password);
    void displayInfo() const;
    friend class bookingagentJsonSerializer; 
};

#endif