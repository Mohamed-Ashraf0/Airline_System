#ifndef PASSENGER_HANDLER_HPP
#define PASSENGER_HANDLER_HPP

#include <memory>
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"
#include "Entities/Passenger.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Passenger_Serializer.hpp"
#include "Input_Handler.hpp"
#include "bcrypt.h"

#define REMOVE_ADD_OPTION false

class passengerhandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;

public:
    passengerhandler();

    Passenger login(const std::string &username, const std::string &password);
    void addPassenger(Passenger &passenger);
    Passenger choosePassenger(bool allowAddOption = true);
    void updatePassenger( Passenger &passenger);
    void deletePassenger(const std::string &passengerId);
    void viewAllPassengers();
    Passenger getPassengerById(const std::string &passengerId);
    std::pair<int, std::vector<std::tuple<std::string, std::string, std::vector<std::string>>>>getAllPassengers();
};

#endif