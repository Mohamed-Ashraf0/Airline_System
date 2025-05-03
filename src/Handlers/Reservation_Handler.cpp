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
Reservation reservationHandler::chooseReservation(bool allowAddOption, bool allowCancelOption) 
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No reservations available.\n");
    }
    std::cout << "--- Available Reservations ---\n";
    int index = 1;
    std::vector<std::string> reservationIds;
    for (auto &[id, reservationJson] : j.items())
    {
        if (id == "lastId")
            continue;
        if (allowCancelOption && reservationJson["status"] == "Cancelled")
        {
            continue;
        }
        std::cout << index << ". Reservation ID: " << id << "\n";
        std::cout << "   Flight ID: " << reservationJson["flightId"] << "\n";
        std::cout << "   Passenger ID: " << reservationJson["passengerId"] << "\n";
        std::cout << "   Status: " << reservationJson["status"] << "\n";
        std::cout << "   Seat: " << reservationJson["seat"] << "\n";
        std::cout << "   Payment Method ID: " << reservationJson["paymentMethodId"] << "\n\n";
        reservationIds.push_back(id);
        index++;
    }
    if (allowAddOption)
    {
        std::cout << index << ". Add new Reservation\n";
    }
    if(index == 1)
    {
        throw std::runtime_error("No reservations available.\n");
    }
    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index)
    {
        throw std::runtime_error("");
    }
    nlohmann::json selectedReservation = j[reservationIds[choice - 1]];
    selectedReservation["id"] = reservationIds[choice - 1];
    
    return reservationJsonSerializer::deserialize(selectedReservation);
}