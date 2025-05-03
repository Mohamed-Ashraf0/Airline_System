#include "Entities/Maintenance.hpp"

// Constructor
Maintenance::Maintenance (const std::string &date, const std::string &aircraftId, const std::string &details)
    : date(date), aircraftId(aircraftId), details(details) {}

// Getters
const std::string &Maintenance::getId() const {
    return id;
}

const std::string &Maintenance::getDate() const {
    return date;
}

const std::string &Maintenance::getAircraftId() const {
    return aircraftId;
}

const std::string &Maintenance::getDetails() const {
    return details;
}

// Setters
void Maintenance::setId(const std::string &id) {
    this->id = id;
}

void Maintenance::setDate(const std::string &date) {
    this->date = date;
}

void Maintenance::setAircraftId(const std::string &aircraftId) {
    this->aircraftId = aircraftId;
}

void Maintenance::setDetails(const std::string &details) {
    this->details = details;
}

// Display Information
void Maintenance::displayInfo() const {
    std::cout << "Maintenance ID: " << id << "\n"
              << "Date: " << date << "\n"
              << "Aircraft ID: " << aircraftId << "\n"
              << "Details: " << details << "\n";
}