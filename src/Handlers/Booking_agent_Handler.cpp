#include "Handlers/Booking_agent_Handler.hpp"

bookingagenthandler::bookingagenthandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Booking_agent.json")) {}

BookingAgent bookingagenthandler::login(const std::string &username, const std::string &password)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No booking agents available.\n");
    }
    for (auto &[id, agentJson] : j.items())
    {
        if (id == "lastId")
            continue;

        if (agentJson["username"] == username)
        {
            const std::string &storedHash = agentJson["password"];
            if (bcrypt_checkpw(password.c_str(), storedHash.c_str()) == 0)
            {
                agentJson["id"] = id;
                return bookingagentJsonSerializer::deserialize(agentJson);
            }
        }
    }
    throw std::runtime_error("Invalid username or password.");
}

void bookingagenthandler::addBookingAgent(BookingAgent &agent)
{
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
        for (auto &[id, agentJson] : j.items())
        {
            if (id == "lastId")
                continue;

            if (agentJson["username"] == agent.getUsername())
            {
                throw std::runtime_error("Booking agent with this username already exists.");
            }
        }
    }
    char salt[BCRYPT_HASHSIZE];
    char hash[BCRYPT_HASHSIZE];
    strcpy(salt, "$2a$12$abcdefghijklmnopqrstuv");
    if (bcrypt_hashpw(agent.getPassword().c_str(), salt, hash) != 0)
    {
        throw std::runtime_error("Failed to hash the password.");
    }
    agent.setPassword(hash);
    j = bookingagentJsonSerializer::serialize(agent);
    std::string idPrefix = "BA";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    agent.setId(id);
}

BookingAgent bookingagenthandler::chooseBookingAgent(bool allowAddOption)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("No booking agents available.\n");
    }

    std::cout << "--- Available Booking Agents ---\n";
    int index = 1;
    std::vector<std::string> agentIds;

    for (auto &[id, agentJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::cout << index << ". Agent ID: " << id << "\n";
        std::cout << "   Username: " << agentJson["username"] << "\n";
        agentIds.push_back(id);
        index++;
    }

    if (allowAddOption)
    {
        std::cout << index << ". Add new Booking Agent\n";
    }

    int choice = inputHandler.getInteger(allowAddOption ? index : index - 1);
    if (choice == index)
    {
        throw std::runtime_error("");
    }

    // Add the ID to the JSON object before deserializing
    nlohmann::json selectedAgent = j[agentIds[choice - 1]];
    selectedAgent["id"] = agentIds[choice - 1];

    return bookingagentJsonSerializer::deserialize(selectedAgent);
}

void bookingagenthandler::updateBookingAgent(BookingAgent &agent)
{
    char salt[BCRYPT_HASHSIZE];
    char hash[BCRYPT_HASHSIZE];
    strcpy(salt, "$2a$12$abcdefghijklmnopqrstuv");
    if (bcrypt_hashpw(agent.getPassword().c_str(), salt, hash) != 0)
    {
        throw std::runtime_error("Failed to hash the password.");
    }
    agent.setPassword(hash);
    nlohmann::json j = bookingagentJsonSerializer::serialize(agent);
    fileHandler->updateJsonFile(j, agent.getId());
}

void bookingagenthandler::deleteBookingAgent(const std::string &agentId)
{
    fileHandler->deleteEntityById(agentId);
}

void bookingagenthandler::viewAllBookingAgents()
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {

        throw std::runtime_error("No booking agents available.\n");
    }
    int index = 1;
    for (auto &[id, agentJson] : j.items())
    {
        if (id == "lastId")
            continue;

        std::cout << index << ". Agent ID: " << id << "\n";
        std::cout << "   Username: " << agentJson["username"] << "\n";

        index++;
    }
}
