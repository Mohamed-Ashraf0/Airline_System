#include "Handlers/Aircraft_Handler.hpp"

aircrafthandler::aircrafthandler()
    : fileHandler(FileHandler::create("../Airline-Data/Aircraft.json")) {}

Aircraft aircrafthandler::search_aircraft(const std::string &aircraftType, int totalSeats)
{
    nlohmann::json j = fileHandler->search_aircraft(aircraftType, totalSeats);
    return aircraftJsonSerializer::deserialize(j);
}

void aircrafthandler::addaircraft(Aircraft &aircraft)
{
    nlohmann::json j = aircraftJsonSerializer::serialize(aircraft);
    std::string id = fileHandler->writeJsonToFile(j,"A");
    aircraft.setId(id);
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