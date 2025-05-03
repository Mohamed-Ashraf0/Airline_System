#ifndef BOARDING_HANDLER_HPP
#define BOARDING_HANDLER_HPP

#include <memory>
#include <string>
#include "nlohmann/json.hpp"
#include "Entities/Boarding.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Boarding_Serializer.hpp"
#include "Handlers/Input_Handler.hpp"

class boardinghandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;
public:
    boardinghandler();
    void addBoarding(Boarding &boarding);
    void updateBoarding(const Boarding &boarding);
    void removeBoarding(const std::string &boardingId);
    Boarding getBoardingById(const std::string &boardingId);
};

#endif