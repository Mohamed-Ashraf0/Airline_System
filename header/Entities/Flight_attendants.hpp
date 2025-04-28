#ifndef FLIGHT_ATTENDANT_HPP
#define FLIGHT_ATTENDANT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entities/Entity.hpp"

class FlightAttendant {
private:
    std::string id;
    std::string name;
    std::vector<std::string> flightIds;

public:
    FlightAttendant() = default;
    FlightAttendant(const std::string &name);

    const std::string &getId() const;
    const std::string &getName() const;
    const std::vector<std::string> &getFlightIds() const;

    void setId(const std::string &id);
    void setName(const std::string &name);
    void addFlightId(const std::string &flightId);

    void displayInfo() const;
};

#endif