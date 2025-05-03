#ifndef Flight_HPP
#define Flight_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entities/Entity.hpp"

#define ROW 6

class Flight:public Entity
{
private:
    std::string Origin;
    std::string Destination;
    std::string Departure_Date_and_Time;
    std::string Arrival_Date_and_Time;
    std::string Aircraft_id;
    std::string BoardingGate;
    std::string BoardingTime;
    std::vector<std::string> Passengers_id;
    std::vector<std::string> Pilots_id;
    std::vector<std::string> FlightAttendants_id;
    std::string status;
    double cost;
    std::vector<char> seats; 
    int seatCount;
    int availableSeats;
    int seat_to_index(std::string seat) const;
public:
    Flight() = default;
    Flight(std::string Origin, std::string Destination, 
           std::string Departure_Date_and_Time, std::string Arrival_Date_and_Time, 
           std::string Aircraft_id, double cost, int seatCount,std::string status);

    const std::string &getId() const;
    const std::string &getOrigin() const;
    const std::string &getDestination() const;
    const std::string &getDepartureDateAndTime() const;
    const std::string &getArrivalDateAndTime() const;
    const std::string &getAircraftId() const;
    const std::string &getBoardingGate() const;
    const std::vector<std::string> &getPassengers() const;
    const std::vector<std::string> &getPilots() const;
    const std::string &getBoardingTime() const;
    const std::vector<std::string> &getFlightAttendants() const;
    const std::string &getStatus() const;
    double getCost() const;
    const std::vector<char> &getSeats() const;
    int getSeatCount() const;
    int getAvailableSeats() const;

    void setId(const std::string &id);
    void setOrigin(const std::string &origin);
    void setDestination(const std::string &Destination);
    void setDeparture_Date_and_Time(const std::string &Departure_Date_and_Time);
    void setArrival_Date_and_Time(const std::string &Arrival_Date_and_Time);
    void setAircraft_id(const std::string &Aircraft_id);
    void setBoardingGate(const std::string &boardingGate);
    void setBoardingTime(const std::string &boardingTime);
    void setCost(double cost);
    void setStatus(const std::string &status);
    void addPassenger(const std::string &passengerId);
    void removePassenger(const std::string &passengerId);
    void addPilot(const std::string &pilotId);
    void removePilot(const std::string &pilotId);
    void addFlightAttendant(const std::string &flightAttendantId);
    void removeFlightAttendant(const std::string &flightAttendantId);
    void displayInfo() const;
    bool bookSeat(std::string seat);
    bool dropSeat(std::string seat);
    void displaySeats() const;
    friend class flightJsonSerializer;
};
#endif