#include "Handlers/Flight_Handler.hpp"

flighthandler::flighthandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Flight.json")) {}

void flighthandler::addFlight(Flight &flight)
{
    nlohmann::json j = flightJsonSerializer::serialize(flight);
    std::string idPrefix = "F";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    flight.setId(id);
}
Flight flighthandler::chooseFlight(bool allowAddOption,const std::string &passengerId)
{

    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No flights available.\n");
    }
    std::cout << "---Available Flights---\n";

    int index = 1;
    std::vector<std::string> fligtData;
    std::vector<std::string> passengersid;
    for (auto &[id, flightJson] : j.items())
    {
        if (id == "lastId")
        {
            continue;
        }    
        passengersid = flightJson["Passengers_id"];
        if (passengerId != "" && std::find(passengersid.begin(), passengersid.end(), passengerId) != passengersid.end())
        {
            continue;
        }
        std::cout << index << ". Flight ID: " << id<< "\n"
                  << "   Aircraft ID: " << flightJson["Aircraft_id"]<< "\n"
                  << "   Origin: " << flightJson["Origin"]<< "\n"
                  << "   Destination: " << flightJson["Destination"]<< "\n"
                  << "   Departure Date and Time: " << flightJson["Departure_Date_and_Time"]<< "\n"
                  << "   Arrival Date and Time: " << flightJson["Arrival_Date_and_Time"]<< "\n"
                  << "   Total Seats: " << flightJson["seatCount"]<< "\n"
                  << "   Available Seats: " << flightJson["availableSeats"] << "\n"
                  << "   Status: " << flightJson["status"]<< "\n"
                  << "   Cost: " << flightJson["cost"] << "\n";
        std::cout << "   pilot ID: ";
        for (const auto &pilotId : flightJson["Pilots_id"])
        {
            std::cout << pilotId << " ";
        }
        std::cout << "\n";
        std::cout << "   flight attendant ID: ";
        for (const auto &flightAttendantId : flightJson["FlightAttendants_id"])
        {
            std::cout << flightAttendantId << " ";
        }
        std::cout << "\n";
        fligtData.emplace_back(id);
        index++;
    }

    if (allowAddOption)
    {
        std::cout << index << ". Add new Flight\n";
    }
    if (index == 1)
    {
        throw std::runtime_error("No flights available.\n");
    }
    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index)
    {
        throw std::runtime_error("");
    }
    nlohmann::json selectedFlight = j[fligtData[choice - 1]];
    selectedFlight["id"] = fligtData[choice - 1];
    return flightJsonSerializer::deserialize(selectedFlight);
}
void flighthandler::updateFlight(const Flight &flight)
{
    nlohmann::json j = flightJsonSerializer::serialize(flight);
    fileHandler->updateJsonFile(j, flight.getId());
}
void flighthandler::viewAllFlights()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No flights available.\n");
    }
    int index = 1;
    for (auto &[id, flightJson] : j.items())
    {
        if (id == "lastId")
            continue;
        std::cout << index << ". Flight ID: " << id<< "\n"
                  << "   Aircraft ID: " << flightJson["Aircraft_id"]<< "\n"
                  << "   Origin: " << flightJson["Origin"]<< "\n"
                  << "   Destination: " << flightJson["Destination"]<< "\n"
                  << "   Departure Date and Time: " << flightJson["Departure_Date_and_Time"]<< "\n"
                  << "   Arrival Date and Time: " << flightJson["Arrival_Date_and_Time"]<< "\n"
                  << "   Total Seats: " << flightJson["seatCount"]<< "\n"
                  << "   Available Seats: " << flightJson["availableSeats"]<< "\n"
                  << "   Cost: " << flightJson["cost"] << "\n";
        std::cout << "   pilot ID: ";
        for (const auto &pilotId : flightJson["Pilots_id"])
        {
            std::cout << pilotId << " ";
        }
        std::cout << "\n";
        std::cout << "   flight attendant ID: ";
        for (const auto &flightAttendantId : flightJson["FlightAttendants_id"])
        {
            std::cout << flightAttendantId << " ";
        }
        std::cout << "\n";
        index++;
    }
}
void flighthandler::removeFlight(const Flight &flight)
{
    fileHandler->deleteEntityById(flight.getId());
    
}
Flight flighthandler::getFlightById(const std::string &flightId)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No flightss available.\n");
    }
    if (j.empty())
    {
        throw std::runtime_error("Flight not found.\n");
    }
    j[flightId]["id"] = flightId;
    Flight flight = flightJsonSerializer::deserialize(j[flightId]);
    return flight;
}
