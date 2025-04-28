#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entities/Entity.hpp"
#include "serializers/Passenger_Serializer.hpp"

class Passenger:public Entity
{
private:
    std::string username;
    std::string password;
    std::vector<std::string> Reservations_id;
    std::vector<std::string> BoardingPasses_id;
    std::string PaymentMethod;

public:
    Passenger() = default;
    Passenger(const std::string &name, const std::string &password);

    const std::string &getId() const;
    const std::string &getName() const;
    const std::string &getPassword() const;
    const std::vector<std::string> &getReservations() const;
    const std::vector<std::string> &getBoardingPasses() const;
    const std::string &getPaymentMethod() const;
    void setId(const std::string &id);
    void addReservation(const std::string &reservationId);
    void addBoardingPass(const std::string &boardingPassId);
    void setPaymentMethod(const std::string &paymentMethod);
    void displayInfo() const;
    friend class passengerJsonSerializer; 
};

#endif 