#include "Handlers/Flight_Handler.hpp"

flighthandler::flighthandler()
    : fileHandler(FileHandler::create("../Airline-Data/Flight.json")) {}

void flighthandler::addFlight( Flight &flight)
{
    nlohmann::json j = FlightSerializer::serialize(flight);
    std::string id = fileHandler->writeJsonToFile(j,"F");
    flight.setId(id);
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