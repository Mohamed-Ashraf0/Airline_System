#include "Handlers/Aircraft_Handler.hpp"

aircrafthandler::aircrafthandler()
    : fileHandler(FileHandler::create("../../Airline-Data/aircraft.json")) {}

Aircraft aircrafthandler::searchaircraft(const std::string &aircraftType, int totalSeats)
{
    nlohmann::json j = fileHandler->search_aircraft(aircraftType, totalSeats);
    return aircraftJsonSerializer::deserialize(j);
}

void aircrafthandler::addaircraft(Aircraft &aircraft)
{
    nlohmann::json j = aircraftJsonSerializer::serialize(aircraft);
    std::string idPrefix = "A";
    std::string id = fileHandler->writeJsonToFile(j,idPrefix);
    aircraft.setId(id);
}

Aircraft aircrafthandler::chooseaircraft(bool allowAddOption)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No aircrafts available.\n");
    }
    std::cout << "---Available Aircrafts---\n";

    int index = 1;
    std::vector<std::string> aircraftData;

    for (auto &[id, aircraftJson] : j.items())
    {
        if (id == "lastId")
            continue;

        int seatCount = aircraftJson["seatCount"];
        std::cout << index << ". Aircraft ID: " << id<< "\n";
        std::cout << "   Type: " << aircraftJson["Type"] << "\n";
        std::cout << "   Seat Count: " << seatCount << "\n";

        aircraftData.emplace_back(id); 
        index++;
    }

    if (allowAddOption)
    {
        std::cout << index << ". Add new Aircraft\n";
    }

    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index)
    {
        throw std::runtime_error("");
    }
    nlohmann::json selectedAircraft = j[aircraftData[choice - 1]];
    selectedAircraft["id"] = aircraftData[choice - 1];
    return aircraftJsonSerializer::deserialize(selectedAircraft);
}
void aircrafthandler::updateaircraft(const Aircraft &aircraft)
{
    nlohmann::json j = aircraftJsonSerializer::serialize(aircraft);
    fileHandler->updateJsonFile(j, aircraft.getId());
}
void aircrafthandler::removeaircraft(const Aircraft &aircraft)
{
    fileHandler->deleteEntityById(aircraft.getId());
}
void aircrafthandler::viewAllaircrafts()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        
        throw std::runtime_error("No aircrafts available.\n");
    }
    int index = 1;
    for (auto &[id, aircraftJson] : j.items())
    {
        if (id == "lastId")
            continue;
        std::cout << index << ". Aircraft ID: " << id<< "\n";
        std::cout << "   Type: " << aircraftJson["Type"]<< "\n";
        std::cout << "   Seat Count: " << aircraftJson["seatCount"] << "\n";
        index++;
    }
}
