#include "Handlers/Flight_attendants_Handler.hpp"

flightattendantshandler::flightattendantshandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Flight_attendants.json")) {}

void flightattendantshandler::addFlightAttendant(FlightAttendant &attendant)
{
    nlohmann::json j = flightagentJsonSerializer::serialize(attendant);
    std::string idPrefix = "FA";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    attendant.setId(id);
}

FlightAttendant flightattendantshandler::chooseFlightAttendant(bool allowAddOption,std::vector<std::string> flightattendentIds)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {

        throw std::runtime_error("No flight attendants available.\n");
    }
    std::cout << "--- Available Flight Attendants ---\n";
    int index = 1;
    std::vector<std::string> attendantIds;

    for (auto &[id, attendantJson] : j.items())
    {
        if (id == "lastId")
            continue;
        if(!flightattendentIds.empty() && std::find(flightattendentIds.begin(), flightattendentIds.end(), id) != flightattendentIds.end())
        {
            continue;
        }
        std::cout << index << ". Attendant ID: " << id<< "\n";
        std::cout << "   Name: " << attendantJson["name"] << "\n";
        std::cout << "   Flight IDs: ";
        for (const auto &flightId : attendantJson["FlightIDs"])
        {
            std::cout << flightId << " ";
        }
        std::cout << "\n";
        attendantIds.push_back(id);
        index++;
    }

    if (allowAddOption)
    {
        std::cout << index << ". Add new Flight Attendant\n";
    }
    if(index == 1)
    {
        throw std::runtime_error("No flight attendants available.\n");
    }
    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index)
    {
        throw std::runtime_error("");
    }
    nlohmann::json selectedattendant = j[attendantIds[choice - 1]];
    selectedattendant["id"] = attendantIds[choice - 1];
    return flightagentJsonSerializer::deserialize(selectedattendant);
}

void flightattendantshandler::updateFlightAttendant(const FlightAttendant &attendant)
{
    nlohmann::json j = flightagentJsonSerializer::serialize(attendant);
    fileHandler->updateJsonFile(j, attendant.getId());
}

void flightattendantshandler::deleteFlightAttendant(const std::string &attendantId)
{
    fileHandler->deleteEntityById(attendantId);
}

void flightattendantshandler::viewAllFlightAttendants()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No flight attendants available.\n");
    }

    int index = 1;
    for (auto &[id, attendantJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::cout << index << ". Attendant ID: " << id<< "\n";
        std::cout << "   Name: " << attendantJson["name"] << "\n";
        std::cout << "   Flight IDs: ";
        for (const auto &flightId : attendantJson["flightIds"])
        {
            std::cout << flightId << " ";
        }
        std::cout << "\n";
        index++;
    }
}
