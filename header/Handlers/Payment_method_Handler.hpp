#ifndef PASSENGER_HANDLER_HPP
#define PASSENGER_HANDLER_HPP

#include <memory>
#include <string>
#include "json.hpp"
#include "Entities/Payment_method.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Payment_method_Serializer.hpp"

class paymentmethodhandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    paymentmethodhandler();

    Passenger login(const std::string &username, const std::string &password);
    void addPassenger(const Passenger &passenger);
    void updatePassenger(const Passenger &passenger);
    void deletePassenger(const std::string &passengerId);
};

#endif