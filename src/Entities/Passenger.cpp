#include "Entities/Passenger.hpp"

Passenger::Passenger(const std::string &name, const std::string &password)
    : username(name), password(password) {}

const std::string &Passenger::getId() const { return id; }
const std::string &Passenger::getName() const { return username; }
const std::string &Passenger::getPassword() const { return password; }
const std::vector<std::string> &Passenger::getReservations() const { return Reservations_id; }
const std::vector<std::string> &Passenger::getBoardingPasses() const { return BoardingPasses_id; }
const std::string &Passenger::getPaymentMethod() const { return PaymentMethod_id; }

void Passenger::setId(const std::string &id) { this->id = id; }
void Passenger::addReservation(const std::string &reservationId) { Reservations_id.push_back(reservationId); }
void Passenger::addBoardingPass(const std::string &boardingPassId) { BoardingPasses_id.push_back(boardingPassId); }
void Passenger::setPaymentMethod(const std::string &paymentMethodId) { this->PaymentMethod_id = paymentMethodId; }

void Passenger::removeReservation(const std::string &reservationId)
{
    auto it = std::find(Reservations_id.begin(), Reservations_id.end(), reservationId);
    if (it != Reservations_id.end())
    {
        Reservations_id.erase(it);
    }
}
void Passenger::removeBoardingPass(const std::string &boardingPassId)
{
    auto it = std::find(BoardingPasses_id.begin(), BoardingPasses_id.end(), boardingPassId);
    if (it != BoardingPasses_id.end())
    {
        BoardingPasses_id.erase(it);
    }
}   
void Passenger::displayInfo() const
{
    std::cout << "Username: " << username << "\n"
              << "Password: " << password << "\n"
                << "Payment Method: " << PaymentMethod_id << "\n"
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
}
void Passenger::setUsername(const std::string &name) { this->username = name; }
void Passenger::setPassword(const std::string &password) { this->password = password; }