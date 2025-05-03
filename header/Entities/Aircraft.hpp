#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entities/Entity.hpp"

#define  ROW 6 
class Aircraft : public Entity {
private:
    std::string Type;
    int seatCount;
    std::vector<std::string> Maintenance_id;
public:
    Aircraft() = default;
    Aircraft(const std::string &Type, int seatCount);

    const std::string &getId() const;
    const std::string &getType() const;
    const std::vector<std::string> &getMaintenance() const;
    void setId(const std::string &id);
    void setType(const std::string &Type);
    void setSeatCount(int seatCount);
    void addMaintenance(const std::string &maintenanceId);
    void removeMaintenance(const std::string &maintenanceId);
    void displayInfo() const;
    int getSeatCount() const;
    
    friend class aircraftJsonSerializer; 
};

#endif 