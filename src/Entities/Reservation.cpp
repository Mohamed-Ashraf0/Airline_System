#include "Entities/Reservation.hpp"
#include <iostream>


Reservation::Reservation(const std::string &flightId, const std::string &passengerId, const std::string &paymentMethodId)
    : flightId(flightId), passengerId(passengerId), paymentMethodId(paymentMethodId), status("Pending") {}

const std::string &Reservation::getId() const {
    return id;
}

const std::string &Reservation::getFlightId() const {
    return flightId;
}

const std::string &Reservation::getPassengerId() const {
    return passengerId;
}

const std::string &Reservation::getStatus() const {
    return status;
}

const std::string &Reservation::getPaymentMethodId() const {
    return paymentMethodId;
}

// Setters
void Reservation::setId(const std::string &id) {
    this->id = id;
}

void Reservation::setFlightId(const std::string &flightId) {
    this->flightId = flightId;
}

void Reservation::setPassengerId(const std::string &passengerId) {
    this->passengerId = passengerId;
}

void Reservation::setStatus(const std::string &status) {
    this->status = status;
}

void Reservation::setPaymentMethodId(const std::string &paymentMethodId) {
    this->paymentMethodId = paymentMethodId;
}

// Display Information
void Reservation::displayInfo() const {
    std::cout << "Reservation ID: " << id << "\n"
              << "Flight ID: " << flightId << "\n"
              << "Passenger ID: " << passengerId << "\n"
              << "Status: " << status << "\n"
              << "Payment Method ID: " << paymentMethodId << "\n";
}