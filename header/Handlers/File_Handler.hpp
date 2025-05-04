#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <string>
#include "nlohmann/json.hpp"
#include <fstream>
#include <filesystem>
#include <memory>
#include "bcrypt.h"
#include <map> 
#include <vector> 
#include <tuple> 
#include <string>
#include <utility>
class FileHandler
{
private:
    std::string filePath;
    FileHandler(const std::string &path);
    std::string generateIncrementalId(nlohmann::json &existingJson, std::string &entit_prefix);

public:
    nlohmann::json readJsonFromFile();
    static std::unique_ptr<FileHandler> create(const std::string &path);
    std::string writeJsonToFile(const nlohmann::json &j, std::string &entit_prefix);
    void updateJsonFile(const nlohmann::json &j, const std::string &entityId);
    nlohmann::json getEntityJsonById(const std::string &entityId);
    void deleteEntityById(const std::string &entityId);
    nlohmann::json login(const std::string &username, const std::string &password);
    nlohmann::json search_aircraft(const std::string &aircraftType, int totalSeats);

};

#endif