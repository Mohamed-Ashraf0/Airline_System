#ifndef BOARDING_HPP
#define BOARDING_HPP

#include <iostream>
#include <string>
#include <chrono>
#include "Entities/Entity.hpp"

class Boarding : public Entity{
private:
    std::string passengerId;
    std::string flightId;
    std::string reservationId;

public:
    Boarding() = default;
    Boarding(const std::string &passengerId, const std::string &flightId, const std::string &reservationId);
    const std::string &getPassengerId() const;
    const std::string &getFlightId() const;
    const std::string &getId() const override;
    const std::string &getReservationId() const;
    void setPassengerId(const std::string &passengerId);
    void setFlightId(const std::string &flightId);
    void setId(const std::string &id) override;
    void setReservationId(const std::string &reservationId);
    void displayInfo() const;
};

#endif 