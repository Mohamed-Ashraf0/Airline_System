#include "Handlers/File_Handler.hpp"

FileHandler::FileHandler(const std::string &path) : filePath(path) {}

std::string FileHandler::generateIncrementalId(nlohmann::json &existingJson,std::string &entit_prefix)
{
    int lastId = 0;
    if (existingJson.contains("lastId"))
    {
        lastId = existingJson["lastId"];
    }

    lastId++;
    existingJson["lastId"] = lastId;
    return entit_prefix + std::to_string(lastId);
}

nlohmann::json FileHandler::readJsonFromFile()
{
    std::ifstream inputFile(filePath);
    if (!inputFile)
    {
        throw std::runtime_error("Failed to open the file for reading: " + filePath);
    }
    nlohmann::json jsonData;
    inputFile >> jsonData;
    inputFile.close();
    return jsonData;
}

std::unique_ptr<FileHandler> FileHandler::create(const std::string &path)
{
    if (!std::filesystem::exists(path))
    {
        throw std::runtime_error("No file exists at the specified path: " + path);
    }
    return std::unique_ptr<FileHandler>(new FileHandler(path));
}

std::string FileHandler::writeJsonToFile(const nlohmann::json &j,std::string &entit_prefix)
{
    nlohmann::json existingJson;
    std::ifstream inputFile(filePath);
    if (inputFile.peek() == std::ifstream::traits_type::eof())
    {
        existingJson = nlohmann::json::object();
    }
    else
    {
        inputFile >> existingJson;
    }
    inputFile.close();
    std::string entityId = generateIncrementalId(existingJson, entit_prefix);
    existingJson[entityId] = j;
    std::ofstream outputFile(filePath, std::ios::trunc);
    if (!outputFile)
    {
        throw std::runtime_error("Failed to open the file for writing: " + filePath);
    }
    outputFile << existingJson.dump(4);
    outputFile.close();
    return entityId;
}

void FileHandler::updateJsonFile(const nlohmann::json &j, const std::string &entityId)
{
    nlohmann::json existingJson = readJsonFromFile();
    if (!existingJson.contains(entityId))
    {
        throw std::runtime_error("Entity ID not found: " + entityId);
    }
    existingJson[entityId] = j;
    std::ofstream outputFile(filePath, std::ios::trunc);
    if (!outputFile)
    {
        throw std::runtime_error("Failed to open the file for writing: " + filePath);
    }
    outputFile << existingJson.dump(4);
    outputFile.close();
}

nlohmann::json FileHandler::getEntityJsonById(const std::string &entityId)
{
    nlohmann::json existingJson = readJsonFromFile();
    if (!existingJson.contains(entityId))
    {
        throw std::runtime_error("Entity ID not found: " + entityId);
    }
    return existingJson[entityId];
}

void FileHandler::deleteEntityById(const std::string &entityId)
{
    nlohmann::json existingJson = readJsonFromFile();
    if (!existingJson.contains(entityId))
    {
        throw std::runtime_error("Entity ID not found: " + entityId);
    }
    existingJson.erase(entityId);
    std::ofstream outputFile(filePath, std::ios::trunc);
    if (!outputFile)
    {
        throw std::runtime_error("Failed to open the file for writing: " + filePath);
    }
    outputFile << existingJson.dump(4);
    outputFile.close();
}

nlohmann::json FileHandler::login(const std::string &username, const std::string &password)
{
    nlohmann::json existingJson = readJsonFromFile();
    for (auto &[id, userJson] : existingJson.items())
    {
        if (id == "lastId")
            continue;
        if (userJson["username"] == username)
        {
            if (userJson["password"] == password)
            {
                return passengerJson;
            }
            else
            {
                throw std::runtime_error("Invalid password.");
            }
        }
    }
    throw std::runtime_error("Username not found.");
}
nlohmann::json FileHandler::search_aircraft(const std::string &aircraftType, int totalSeats)
{
    nlohmann::json existingJson = readJsonFromFile();
    for (auto &[id, aircraftJson] : existingJson.items())
    {
        if (id == "lastId")
            continue;
        if (aircraftJson["Type"] == aircraftType && aircraftJson["seatCount"] >= totalSeats)
        {
            return aircraftJson;
        }
    }
    throw std::runtime_error("No matching aircraft found.");
}

