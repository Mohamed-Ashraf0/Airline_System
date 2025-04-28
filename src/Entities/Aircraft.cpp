#include "Entities/Aircraft.hpp"
#include <iostream>

Aircraft::Aircraft(const std::string &Type, int seatCount)
    : Type(Type), seatCount(seatCount)
{
    
}

const std::string &Aircraft::getId() const
{
    return id;
}

const std::string &Aircraft::getType() const
{
    return Type;
}

void Aircraft::setId(const std::string &id)
{
    this->id = id;
}

void Aircraft::setType(const std::string &Type)
{
    this->Type = Type;
}


void Aircraft::setSeatCount(int seatCount)
{
    this->seatCount = seatCount;
}
void Aircraft::addMaintenance(const std::string &maintenanceId)
{
    Maintenance_id.push_back(maintenanceId);
}
int Aircraft::getSeatCount() const
{
    return seatCount;
}
void Aircraft::displayInfo() const
{
    std::cout << "Aircraft ID: " << id << "\n"
              << "Type: " << Type << "\n"
              << "Seat Count: " << seatCount << "\n";
    std::cout << "Maintenance IDs: ";
    for (const auto &maintenanceId : Maintenance_id)
    {
        std::cout << maintenanceId << " ";
    }
}