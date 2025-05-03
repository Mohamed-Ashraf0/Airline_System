#include "Handlers/Menu_Handler.hpp"

std::unique_ptr<Menu> MenuHandler::getMenu() {
    std::cout << "Welcome to Airline Reservation and Management System\n";
    std::cout << "Please select your role:\n";
    std::cout << "1. Administrator\n";
    std::cout << "2. Booking Agent\n";
    std::cout << "3. Passenger\n";

    int choice;
    choice = inputHandler.getInteger(3); 

    switch (choice) {
        case 1:
            return std::make_unique<AdminMenu>();
        case 2:
            return std::make_unique<BookingAgentMenu>();
        case 3:
            return std::make_unique<PassengerMenu>();
        default:
        return nullptr; 
        break;
    }
}