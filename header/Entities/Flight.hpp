#ifndef Flight_HPP
#define Flight_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entities/Entity.hpp"
#include "serializers/Flight_Serializer.hpp"
#define ROW 6

enum class FlightStatus
{
    SCHEDULED,
    DELAYED,
    CANCELLED,
};
class Flight:public Entity
{
private:
    std::string Origin;
    std::string Destination;
    std::string Departure_Date_and_Time;
    std::string Arrival_Date_and_Time;
    std::string Aircraft_id;
    std::string BoardingGate;
    std::vector<std::string> Passengers_id;
    FlightStatus status;
    double cost;
    std::vector<char> seats; 
    int seatCount;
    int availableSeats;
public:
    Flight() = default;
    Flight(std::string Origin, std::string Destination, 
           std::string Departure_Date_and_Time, std::string Arrival_Date_and_Time, 
           std::string Aircraft_id, double cost, int seatCount);

    const std::string &getId() const;
    const std::string &getOrigin() const;
    const std::string &getDestination() const;
    const std::string &getBoardingGate() const;
    void setBoardingGate(const std::string &boardingGate);
    FlightStatus getStatus() const;
    const std::string &getDepartureDateAndTime() const;
    const std::string &getArrivalDateAndTime() const;
    const std::string &getAircraftId() const;
    double getCost() const;
    const std::vector<std::string> &getPassengers() const;
    void setId(const std::string &id);
    void setOrigin(const std::string &origin);
    void setDestination(const std::string &Destination);
    void setDeparture_Date_and_Time(const std::string &Departure_Date_and_Time);
    void setArrival_Date_and_Time(const std::string &Arrival_Date_and_Time);
    void setAircraft_id(const std::string &Aircraft_id);
    void setCost(double cost);
    void setStatus(FlightStatus status);
    void addPassenger(const std::string &passengerId);
    void removePassenger(const std::string &passengerId);
    void displayInfo() const;
    void bookSeat(int index);
    void dropSeat(int index);
    void displaySeats() const;
    friend class FlightJsonSerializer;
};
#endif