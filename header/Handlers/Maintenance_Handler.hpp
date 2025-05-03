#ifndef MAINTENANCE_HANDLER_HPP
#define MAINTENANCE_HANDLER_HPP

#include <memory>
#include <string>
#include "nlohmann/json.hpp"
#include "Entities/Maintenance.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Maintenance_Serializer.hpp"
#include "Input_Handler.hpp"
#define REMOVE_ADD_OPTION false

class maintenancehandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;

public:
    maintenancehandler();
    void addMaintenance(Maintenance &maintenance);
    Maintenance chooseMaintenance(bool allowAddOption = true, const std::vector<std::string> &maintenanceIds = {});
    void updateMaintenance(const Maintenance &maintenance);
    void removeMaintenance(const std::string &maintenanceId);
    void viewmyMaintenances(const std::vector<std::string> &maintenanceIds);

};

#endif