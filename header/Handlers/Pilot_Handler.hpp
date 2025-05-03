#ifndef PILOT_HANDLER_HPP
#define PILOT_HANDLER_HPP

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include "nlohmann/json.hpp"
#include "Entities/Pilot.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Pilot_Serializer.hpp"
#include "Input_Handler.hpp"

#define REMOVE_ADD_OPTION false

class pilothandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;

public:
    pilothandler();

    void addPilot(Pilot &pilot);
    Pilot choosePilot(bool allowAddOption = true,std::vector<std::string> PilotIds = {});
    void updatePilot(const Pilot &pilot);
    void deletePilot(const std::string &pilotId);
    void viewAllPilots();
};

#endif