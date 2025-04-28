#ifndef FLIGHT_HANDLER_HPP
#define FLIGHT_HANDLER_HPP

#include <memory>
#include <string>
#include "json.hpp"
#include "Entities/Flight.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Flight_Serializer.hpp"

class flighthandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    flighthandler();

    void addFlight( Flight &flight);
    void updatePassenger(const Passenger &passenger);
    void deletePassenger(const std::string &passengerId);
};

#endif