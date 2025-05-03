#include "Handlers/Reservation_Handler.hpp"

reservationHandler::reservationHandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Reservation.json")) {}

void reservationHandler::addReservation( Reservation &reservation) 
{
    nlohmann::json j = reservationJsonSerializer::serialize(reservation);
    std::string idPrefix = "R";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    reservation.setId(id);
}

void reservationHandler::updateReservation(const Reservation &reservation) 
{
    nlohmann::json j = reservationJsonSerializer::serialize(reservation);
    fileHandler->updateJsonFile(j, reservation.getId());
}
void reservationHandler::removeReservation(const std::string &reservationId) 
{
    fileHandler->deleteEntityById(reservationId);
}
Reservation reservationHandler::getReservation(const std::string &reservationId) 
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("Reservation not found.\n");
    }    
    if (j.find(reservationId) == j.end())
    {
        throw std::runtime_error("Reservation not found.\n");
    }
    j[reservationId]["id"] = reservationId;
    Reservation reservation = reservationJsonSerializer::deserialize(j[reservationId]);
    reservation.setId(reservationId);
    return reservation;
}