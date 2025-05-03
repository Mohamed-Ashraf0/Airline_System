#ifndef FLIGHT_HANDLER_HPP
#define FLIGHT_HANDLER_HPP

#include <memory>
#include <string>
#include "nlohmann/json.hpp"
#include "Entities/Flight.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Flight_Serializer.hpp"
#include "Input_Handler.hpp"

#define REMOVE_ADD_OPTION false

class flighthandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;
public:
    flighthandler();

    void addFlight( Flight &flight);
    Flight chooseFlight(bool allowAddOption=true,const std::string &passengerId = "");
    void updateFlight(const Flight &flight);
    void removeFlight(const Flight &flight);
    void viewAllFlights();
    Flight getFlightById(const std::string &flightId);

};

#endif