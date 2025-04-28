#ifndef PASSENGER_HANDLER_HPP
#define PASSENGER_HANDLER_HPP

#include <memory>
#include <string>
#include "json.hpp"
#include "Entities/Maintenance.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Maintenance_Serializer.hpp"

class maintenancehandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    maintenancehandler();

    Passenger login(const std::string &username, const std::string &password);
    void addPassenger(const Passenger &passenger);
    void updatePassenger(const Passenger &passenger);
    void deletePassenger(const std::string &passengerId);
};

#endif