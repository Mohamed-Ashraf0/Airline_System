#include "Entities/Booking_agent.hpp"
#include <iostream>

BookingAgent::BookingAgent(const std::string &username, const std::string &password)
    : username(username), password(password) {}

const std::string &BookingAgent::getId() const {
    return id;
}

const std::string &BookingAgent::getUsername() const {
    return username;
}

const std::string &BookingAgent::getPassword() const {
    return password;
}

// Setters
void BookingAgent::setId(const std::string &id) {
    this->id = id;
}

void BookingAgent::setUsername(const std::string &username) {
    this->username = username;
}

void BookingAgent::setPassword(const std::string &password) {
    this->password = password;
}


void BookingAgent::displayInfo() const {
    std::cout << "Booking Agent ID: " << id << "\n"
              << "Username: " << username << "\n"
              << "Password: " << password << "\n";
}