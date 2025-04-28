#include "Entities/Pilot.hpp"
#include <iostream>

Pilot::Pilot( const std::string &name)
    : name(name) {}

const std::string &Pilot::getId() const {
    return id;
}

const std::string &Pilot::getName() const {
    return name;
}

const std::vector<std::string> &Pilot::getFlightIds() const {
    return flightIds;
}

void Pilot::setId(const std::string &id) {
    this->id = id;
}

void Pilot::setName(const std::string &name) {
    this->name = name;
}

void Pilot::addFlightId(const std::string &flightId) {
    flightIds.push_back(flightId);
}

void Pilot::displayInfo() const {
    std::cout << "Pilot ID: " << id << "\n"
              << "Name: " << name << "\n"
              << "Assigned Flights: ";
    for (const auto &flightId : flightIds) {
        std::cout << flightId << " ";
    }
    std::cout << "\n";
}