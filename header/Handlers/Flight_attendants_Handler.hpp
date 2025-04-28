#ifndef FLIGHT_ATTENDANTS_HANDLER_HPP
#define FLIGHT_ATTENDANTS_HANDLER_HPP

#include <memory>
#include <string>
#include "json.hpp"
#include "Entities/Flight_attendants.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Flight_attendants_Serializer.hpp"

class flightattendantshandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    flightattendantshandler();

    Passenger login(const std::string &username, const std::string &password);
    void addPassenger(const Passenger &passenger);
    void updatePassenger(const Passenger &passenger);
    void deletePassenger(const std::string &passengerId);
};

#endif