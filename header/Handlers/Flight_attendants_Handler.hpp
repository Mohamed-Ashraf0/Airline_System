#ifndef FLIGHT_ATTENDANTS_HANDLER_HPP
#define FLIGHT_ATTENDANTS_HANDLER_HPP

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "nlohmann/json.hpp"
#include "Entities/Flight_attendants.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Flight_attendants_Serializer.hpp"
#include "Input_Handler.hpp"

#define REMOVE_ADD_OPTION false

class flightattendantshandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;

public:
    flightattendantshandler();

    void addFlightAttendant(FlightAttendant &flightAttendant);
    FlightAttendant chooseFlightAttendant(bool allowAddOption = true,std::vector<std::string> flightattendentIds = {});
    void updateFlightAttendant(const FlightAttendant &flightAttendant);
    void deleteFlightAttendant(const std::string &flightAttendantId);
    void viewAllFlightAttendants();
};

#endif