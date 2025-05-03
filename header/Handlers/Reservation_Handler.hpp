#ifndef RESERVATION_HANDLER_HPP
#define RESERVATION_HANDLER_HPP

#include <memory>
#include <string>
#include "nlohmann/json.hpp"
#include "Entities/Reservation.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Reservation_Serializer.hpp"
#include "Input_Handler.hpp"

class reservationHandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;
    InputHandler inputHandler;
public:

    reservationHandler();
    void addReservation( Reservation &reservation);
    void updateReservation(const Reservation &reservation);
    void removeReservation(const std::string &reservationId);
    Reservation getReservation(const std::string &reservationId);
};

#endif