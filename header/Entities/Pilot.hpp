#ifndef PILOT_HPP
#define PILOT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entities/Entity.hpp"

class Pilot: public Entity {
private:

    std::string name;
    std::vector<std::string> flightIds;

public:

    Pilot() = default;
    Pilot( const std::string &name);

    const std::string &getId() const;
    const std::string &getName() const;
    const std::vector<std::string> &getFlightIds() const;

    void setId(const std::string &id);
    void setName(const std::string &name);
    void addFlightId(const std::string &flightId);
    void removeFlightId(const std::string &flightId);
    void displayInfo() const;
    friend class pilotJsonSerializer;
};

#endif 