#include "Handlers/Passenger_Handler.hpp"

passengerhandler::passengerhandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Passenger.json")) {}
Passenger passengerhandler::login(const std::string &username, const std::string &password)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No Passengers available.\n");
    }
    for (auto &[id, passengerJson] : j.items())
    {
        if (id == "lastId")
            continue;

        if (passengerJson["username"] == username)
        {
            const std::string &storedHash = passengerJson["password"];
            if (bcrypt_checkpw(password.c_str(), storedHash.c_str()) == 0)
            {
                passengerJson["id"] = id;
                return passengerJsonSerializer::deserialize(passengerJson);
            }
        }
    }
    throw std::runtime_error("Invalid username or password.");
}
void passengerhandler::addPassenger(Passenger &passenger)
{
    // check that no othe enity has same name
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        j = nlohmann::json::object();
    }
    if (!j.empty())
    {
        for (auto &[id, passengerJson] : j.items())
        {
            if (id == "lastId")
                continue;

            if (passengerJson["username"] == passenger.getName())
            {
                throw std::runtime_error("Passenger with this username already exists.");
            }
        }
    }
    char salt[BCRYPT_HASHSIZE];
    char hash[BCRYPT_HASHSIZE];
    strcpy(salt, "$2a$12$abcdefghijklmnopqrstuv");
    if (bcrypt_hashpw(passenger.getPassword().c_str(), salt, hash) != 0)
    {
        throw std::runtime_error("Failed to hash the password.");
    }
    passenger.setPassword(hash);
     j = passengerJsonSerializer::serialize(passenger);
    std::string idPrefix = "P";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    passenger.setId(id);
}
Passenger passengerhandler::choosePassenger(bool allowAddOption)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No passengers available.\n");
    }

    std::cout << "--- Available Passengers ---\n";
    int index = 1;
    std::vector<std::string> passengerIds;

    for (auto &[id, passengerJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::cout << index << ". Passenger ID: " << id << "\n";
        std::cout << "   Username: " << passengerJson["username"] << "\n";
        std::cout << "   Payment Methods: "<< passengerJson["PaymentMethod"] << "\n";
        std::cout << "   Boarding Passes: ";
        for (const auto &boardingPass : passengerJson["BoardingPasses_id"])
        {
            std::cout << boardingPass << " ";
        }
        std::cout << "\n";
        std::cout << "   Reservations: ";
        for (const auto &reservation : passengerJson["Reservations_id"])
        {
            std::cout << reservation << " ";
        }
        std::cout << "\n";
        passengerIds.push_back(id);
        index++;
    }

    if (allowAddOption)
    {
        std::cout << index << ". Add new Passenger\n";
    }

    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index)
    {
        throw std::runtime_error("");
    }
    nlohmann::json selectedPassenger = j[passengerIds[choice - 1]];
    selectedPassenger["id"] = passengerIds[choice - 1];

    return passengerJsonSerializer::deserialize(selectedPassenger);
}
void passengerhandler::updatePassenger(Passenger &passenger)
{
    // check that no othe enity has same name
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        j = nlohmann::json::object();
    }
    if (!j.empty())
    {
        for (auto &[id, passengerJson] : j.items())
        {
            if (id == "lastId")
                continue;

            if (passengerJson["username"] == passenger.getName() && passenger.getId() != id)
            {
                throw std::runtime_error("Passenger with this username already exists.");
            }
        }
    }
    char salt[BCRYPT_HASHSIZE];
    char hash[BCRYPT_HASHSIZE];
    strcpy(salt, "$2a$12$abcdefghijklmnopqrstuv");
    if (bcrypt_hashpw(passenger.getPassword().c_str(), salt, hash) != 0)
    {
        throw std::runtime_error("Failed to hash the password.");
    }
    passenger.setPassword(hash);
    j = passengerJsonSerializer::serialize(passenger);
    fileHandler->updateJsonFile(j, passenger.getId());
}
void passengerhandler::deletePassenger(const std::string &passengerId)
{
    fileHandler->deleteEntityById(passengerId);
}
void passengerhandler::viewAllPassengers()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No passengers available.\n");
    }

    int index = 1;
    for (auto &[id, passengerJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::cout << index << ". Passenger ID: " << id << "\n";
        std::cout << "   Username: " << passengerJson["username"] << "\n";
        std::cout << "   Payment Methods: "<< passengerJson["PaymentMethod"] << "\n";
        std::cout << "   Boarding Passes: ";
        for (const auto &boardingPass : passengerJson["BoardingPasses_id"])
        {
            std::cout << boardingPass << " ";
        }
        std::cout << "\n";

        std::cout << "   Reservations: ";
        for (const auto &reservation : passengerJson["Reservations_id"])
        {
            std::cout << reservation << " ";
        }
        std::cout << "\n";

        index++;
    }
}
Passenger passengerhandler::getPassengerById(const std::string &passengerId)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No passengers available.\n");
    }
    if (j.find(passengerId) == j.end())
    {
        throw std::runtime_error("Passenger not found.\n");
    }
    j[passengerId]["id"] = passengerId;
    Passenger selectedPassenger = passengerJsonSerializer::deserialize(j[passengerId]);
    return selectedPassenger;
}
std::pair<int, std::vector<std::tuple<std::string, std::string, std::vector<std::string>>>> passengerhandler::getAllPassengers()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No passengers available.\n");
    }

    int totalPassengers = 0;
    std::vector<std::tuple<std::string, std::string, std::vector<std::string>>> passengerDetails;

    for (auto &[id, passengerJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::string passengerId = id;
        std::string username = passengerJson["username"];
        std::vector<std::string> reservations = passengerJson["Reservations_id"].get<std::vector<std::string>>();

        passengerDetails.emplace_back(passengerId, username, reservations);
        totalPassengers++;
    }

    return {totalPassengers, passengerDetails};
}