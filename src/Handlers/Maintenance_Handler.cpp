#include "Handlers/Maintenance_Handler.hpp"

maintenancehandler::maintenancehandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Maintenance.json")) {}

void maintenancehandler::addMaintenance(Maintenance &maintenance)
{
    nlohmann::json j = maintenanceJsonSerializer::serialize(maintenance);
    std::string idPrefix = "MNT";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    maintenance.setId(id);
}

Maintenance maintenancehandler::chooseMaintenance(bool allowAddOption, const std::vector<std::string> &maintenanceIds)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No maintenance available.\n");
    }

    std::cout << "--- Available Maintenance Records ---\n";
    int index = 1;
    std::vector<std::string> availableIds;

    for (auto &[id, maintenanceJson] : j.items())
    {
        if (id == "lastId")
            continue;

        if (std::find(maintenanceIds.begin(), maintenanceIds.end(), id) == maintenanceIds.end())
        {
            continue;
        }

        std::cout << index << ". Maintenance ID: " << id << "\n";
        std::cout << "   Date: " << maintenanceJson["date"] << "\n";
        std::cout << "   Aircraft ID: " << maintenanceJson["aircraftId"] << "\n";
        std::cout << "   Details: " << maintenanceJson["details"] << "\n";
        availableIds.push_back(id);
        index++;
    }

    if (allowAddOption)
    {
        std::cout << index << ". Add new Maintenance Record\n";
    }

    if (index == 1)
    {
        throw std::runtime_error("No maintenance available.\n");
    }

    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index && allowAddOption)
    {
        throw std::runtime_error("");
    }

    nlohmann::json selectedMaintenance = j[availableIds[choice - 1]];
    selectedMaintenance["id"] = availableIds[choice - 1];
    return maintenanceJsonSerializer::deserialize(selectedMaintenance);
}

void maintenancehandler::updateMaintenance(const Maintenance &maintenance)
{
    nlohmann::json j = maintenanceJsonSerializer::serialize(maintenance);
    fileHandler->updateJsonFile(j, maintenance.getId());
}

void maintenancehandler::removeMaintenance(const std::string &maintenanceId)
{
    fileHandler->deleteEntityById(maintenanceId);
}

void maintenancehandler::viewmyMaintenances(const std::vector<std::string> &maintenanceIds)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No maintenance records available.\n");
    }

    int index = 1;
    for (auto &[id, maintenanceJson] : j.items())
    {
        if (id == "lastId")
            continue;
        if (std::find(maintenanceIds.begin(), maintenanceIds.end(), id) == maintenanceIds.end())
        {
            continue;
        }
        std::cout << index << ". Maintenance ID: " << id << "\n";
        std::cout << "   Date: " << maintenanceJson["date"] << "\n";
        std::cout << "   Aircraft ID: " << maintenanceJson["aircraftId"] << "\n";
        std::cout << "   Details: " << maintenanceJson["details"] << "\n";
        index++;
    }
    if (index == 1)
    {
        throw std::runtime_error("No maintenance records available.\n");
    }
}
std::pair<int, std::vector<std::tuple<std::string, std::string, std::string, std::string>>> maintenancehandler::getAllMaintenances()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No maintenance records available.\n");
    }

    int totalMaintenance = 0;
    std::vector<std::tuple<std::string, std::string, std::string, std::string>> maintenanceDetails;

    for (auto &[id, maintenanceJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::string maintenanceId = id;
        std::string date = maintenanceJson["date"];
        std::string aircraftId = maintenanceJson["aircraftId"];
        std::string details = maintenanceJson["details"];

        maintenanceDetails.emplace_back(maintenanceId, date, aircraftId, details);
        totalMaintenance++;
    }

    return {totalMaintenance, maintenanceDetails};
}