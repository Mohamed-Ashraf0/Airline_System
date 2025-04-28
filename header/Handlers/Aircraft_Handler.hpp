#ifndef AIRCRAFT_HANDLER_HPP
#define AIRCRAFT_HANDLER_HPP

#include <memory>
#include <string>
#include "json.hpp"
#include "Entities/Aircraft.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Aircraft_Serializer.hpp"

class aircrafthandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    aircrafthandler();

    Aircraft search_aircraft(const std::string &aircraftType, int totalSeats);
    void addaircraft( Aircraft &aircraft);
    void updatePassenger(const Passenger &passenger);
    void deletePassenger(const std::string &passengerId);
};

#endif