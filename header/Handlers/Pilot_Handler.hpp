#ifndef PASSENGER_HANDLER_HPP
#define PASSENGER_HANDLER_HPP

#include <memory>
#include <string>
#include "json.hpp"
#include "Entities/Pilot.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Pilot_Serializer.hpp"

class pilothandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    pilothandler();

    Pilot login(const std::string &username, const std::string &password);
    void addPilot(const Pilot &pilot);
    void updatePilot(const Pilot &pilot);
    void deletePilot(const std::string &pilotId);
};

#endif