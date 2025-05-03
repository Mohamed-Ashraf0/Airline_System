#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <string>
#include "Entities/Entity.hpp"

class Reservation {
private:
    std::string id;
    std::string flightId;
    std::string passengerId;
    std::string status;
    std::string seat;
    std::string paymentMethodId;

public:
    Reservation() = default;
    Reservation(const std::string &flightId, const std::string &passengerId, const std::string &paymentMethodId);

    const std::string &getId() const;
    const std::string &getFlightId() const;
    const std::string &getPassengerId() const;
    const std::string &getStatus() const;
    const std::string &getPaymentMethodId() const;
    const std::string &getSeat() const;
    
    void setId(const std::string &id);
    void setFlightId(const std::string &flightId);
    void setPassengerId(const std::string &passengerId);
    void setStatus(const std::string &status);
    void setPaymentMethodId(const std::string &paymentMethodId);
    void setSeat(const std::string &seat);
    void displayInfo() const;
    friend class reservationJsonSerializer; // Allow the serializer to access private members
};

#endif