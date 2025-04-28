#include "Entities/Passenger.hpp"

Passenger::Passenger(const std::string &name, const std::string &password)
    : username(name), password(password) {}

const std::string &Passenger::getId() const { return id; }
const std::string &Passenger::getName() const { return username; }
const std::string &Passenger::getPassword() const { return password; }
const std::vector<std::string> &Passenger::getReservations() const { return Reservations_id; }
const std::vector<std::string> &Passenger::getBoardingPasses() const { return BoardingPasses_id; }
const std::string &Passenger::getPaymentMethod() const { return PaymentMethod; }

void Passenger::setId(const std::string &id) { this->id = id; }
void Passenger::addReservation(const std::string &reservationId) { Reservations_id.push_back(reservationId); }
void Passenger::addBoardingPass(const std::string &boardingPassId) { BoardingPasses_id.push_back(boardingPassId); }
void Passenger::setPaymentMethod(const std::string &paymentMethod) { PaymentMethod = paymentMethod; }

void Passenger::displayInfo() const
{
    std::cout << "Username: " << username << "\n"
              << "Password: " << password << "\n"
              << "Reservations: ";
    for (const auto &reservation : Reservations_id)
    {
        std::cout << reservation << " ";
    }
    std::cout << "\nBoarding Passes: ";
    for (const auto &boardingPass : BoardingPasses_id)
    {
        std::cout << boardingPass << " ";
    }
    std::cout << "\nPayment Method: " << PaymentMethod << "\n";
}