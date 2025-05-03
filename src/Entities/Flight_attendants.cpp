#include "Entities/Flight_attendants.hpp"
#include <iostream>

FlightAttendant::FlightAttendant(const std::string &name)
    : name(name) {}

const std::string &FlightAttendant::getId() const {
    return id;
}

const std::string &FlightAttendant::getName() const {
    return name;
}

const std::vector<std::string> &FlightAttendant::getFlightIds() const {
    return flightIds;
}

void FlightAttendant::setId(const std::string &id) {
    this->id = id;
}

void FlightAttendant::setName(const std::string &name) {
    this->name = name;
}

void FlightAttendant::addFlightId(const std::string &flightId) {
    flightIds.push_back(flightId);
}

void FlightAttendant::displayInfo() const {
    std::cout << "Flight Attendant ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Assigned Flights: ";
    for (const auto &flightId : flightIds) {
        std::cout << flightId << " ";
    }
    std::cout << "\n";
}
void FlightAttendant::removeFlightId(const std::string &flightId) {
    auto it = std::remove(flightIds.begin(), flightIds.end(), flightId);
    if (it != flightIds.end()) {
        flightIds.erase(it, flightIds.end());
    }
}