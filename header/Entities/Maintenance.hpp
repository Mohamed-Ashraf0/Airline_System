#ifndef MAINTENANCE_HPP
#define MAINTENANCE_HPP

#include <iostream>
#include <string>
#include "Entities/Entity.hpp"

class Maintenance: public Entity {
private:
    std::string date;  
    std::string aircraftId;
    std::string details;

public:
    Maintenance() = default;
    Maintenance(const std::string &date, const std::string &aircraftId, const std::string &details);

    const std::string &getId() const;
    const std::string &getDate() const;
    const std::string &getAircraftId() const;
    const std::string &getDetails() const;

    void setId(const std::string &id);
    void setDate(const std::string &date);
    void setAircraftId(const std::string &aircraftId);
    void setDetails(const std::string &details);

    void displayInfo() const;
};

#endif