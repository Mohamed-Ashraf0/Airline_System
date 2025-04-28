#include "Entities/Boarding.hpp"
#include <iostream>

Boarding::Boarding(const std::string &passengerId, const std::string &flightId, const std::string &reservationId)
    : passengerId(passengerId), flightId(flightId), reservationId(reservationId) {}

const std::string &Boarding::getPassengerId() const {
    return passengerId;
}

const std::string &Boarding::getFlightId() const {
    return flightId;
}

const std::string &Boarding::getId() const {
    return reservationId; 
}

const std::string &Boarding::getReservationId() const {
    return reservationId;
}


void Boarding::setPassengerId(const std::string &passengerId) {
    this->passengerId = passengerId;
}

void Boarding::setFlightId(const std::string &flightId) {
    this->flightId = flightId;
}

void Boarding::setId(const std::string &id) {
    this->reservationId = id; 
}

void Boarding::setReservationId(const std::string &reservationId) {
    this->reservationId = reservationId;
}

void Boarding::displayInfo() const {
    std::cout << "Passenger ID: " << passengerId << "\n"
              << "Flight ID: " << flightId << "\n"
              << "Reservation ID: " << reservationId << "\n";
}