#include "Handlers/Boarding_Handler.hpp"

boardinghandler::boardinghandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Boarding.json")) {}
void boardinghandler::addBoarding(Boarding &boarding)
{
    nlohmann::json j = boardingJsonSerializer::serialize(boarding);
    std::string idPrefix = "B";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    boarding.setId(id);
}
void boardinghandler::updateBoarding(const Boarding &boarding)
{
    nlohmann::json j = boardingJsonSerializer::serialize(boarding);
    fileHandler->updateJsonFile(j, boarding.getId());
}
void boardinghandler::removeBoarding(const std::string &boardingId)
{
    fileHandler->deleteEntityById(boardingId);
}
Boarding boardinghandler::getBoardingById(const std::string &boardingId)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("Boarding not found.\n");
    }    
    if (j.find(boardingId) == j.end())
    {
        throw std::runtime_error("Boarding not found.\n");
    }
    j[boardingId]["id"] = boardingId;
    Boarding boarding = boardingJsonSerializer::deserialize(j[boardingId]);
    boarding.setId(boardingId);
    return boarding;
}