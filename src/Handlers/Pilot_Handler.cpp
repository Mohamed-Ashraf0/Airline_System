#include "Handlers/Pilot_Handler.hpp"

passengerhandler::passengerhandler()
    : fileHandler(FileHandler::create("../Airline-Data/Passenger.json")) {}

Passenger passengerhandler::login(const std::string &username, const std::string &password)
{
    nlohmann::json j = fileHandler->login(username, password);
    return passengerJsonSerializer::deserialize(j);
}

void passengerhandler::addPassenger(const Passenger &passenger)
{
    nlohmann::json j = passengerJsonSerializer::serialize(passenger);
    fileHandler->writeJsonToFile(j);
}

void passengerhandler::updatePassenger(const Passenger &passenger)
{
    nlohmann::json j = passengerJsonSerializer::serialize(passenger);
    fileHandler->updateJsonFile(j, passenger.getId());
}

void passengerhandler::deletePassenger(const std::string &passengerId)
{
    fileHandler->deletePassengerById(passengerId);
}