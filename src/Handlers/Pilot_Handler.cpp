#include "Handlers/Pilot_Handler.hpp"

pilothandler::pilothandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Pilot.json")) {}

void pilothandler::addPilot(Pilot &pilot)
{
    nlohmann::json j = pilotJsonSerializer::serialize(pilot);
    std::string idPrefix = "PL";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    pilot.setId(id);
}

Pilot pilothandler::choosePilot(bool allowAddOption,std::vector<std::string> Pilotids)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No pilots available.\n");
    }

    std::cout << "--- Available Pilots ---\n";
    int index = 1;
    std::vector<std::string> pilotIds;

    for (auto &[id, pilotJson] : j.items())
    {
        if (id == "lastId")
            continue;
        if(!Pilotids.empty() && std::find(Pilotids.begin(), Pilotids.end(), id) != Pilotids.end())
        {
            continue;
        }
        std::cout << index << ". Pilot ID: " << id<< "\n";
        std::cout << "   Name: " << pilotJson["name"] << "\n";
        std::cout<< "   flight IDs: ";
        for (const auto &flightId : pilotJson["FlightIDs"])
        {
            std::cout << flightId << " ";
        }
        std::cout << "\n";
        pilotIds.push_back(id);
        index++;
    }

    if (allowAddOption)
    {
        std::cout << index << ". Add new Pilot\n";
    }
    if(index == 1)
    {
        throw std::runtime_error("No pilots available.\n");
    }
    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index)
    {
        throw std::runtime_error("");
    }

    nlohmann::json selectedPilot = j[pilotIds[choice - 1]];
    selectedPilot["id"] = pilotIds[choice - 1];

    return pilotJsonSerializer::deserialize(selectedPilot);
}
void pilothandler::updatePilot(const Pilot &pilot)
{
    nlohmann::json j = pilotJsonSerializer::serialize(pilot);
    fileHandler->updateJsonFile(j, pilot.getId());
}

void pilothandler::deletePilot(const std::string &pilotId)
{
    fileHandler->deleteEntityById(pilotId);
}

void pilothandler::viewAllPilots()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No pilots available.\n");
    }
    int index = 1;
    for (auto &[id, pilotJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::cout << index << ". Pilot ID: " << id << "\n";
        std::cout << "   Name: " << pilotJson["name"] << "\n";
        std::cout << "   Flight IDs: ";
        for (const auto &flightId : pilotJson["flightIds"])
        {
            std::cout << flightId << " ";
        }
        std::cout << "\n";

        index++;
    }
}