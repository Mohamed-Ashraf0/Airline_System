#include "Menus/Passenger_Menus.hpp"
PassengerMenu::PassengerMenu()
    : state(PassengerMenuState::LOGIN), inputHandler(), passenger(), currentPassenger(nullptr)
{}
void PassengerMenu::displayMenu() {
    while (state != PassengerMenuState::EXIT) { 
        switch (state) {
            case PassengerMenuState::LOGIN:
                displayLogin();
                break;
            case PassengerMenuState::PASSENGER_MENU:
                displayPassengerMenu();
                break;
            case PassengerMenuState::SEARCH_FLIGHTS:
                displaySearchFlights();
                break;
            case PassengerMenuState::VIEW_RESERVATIONS:
                displayViewReservations();
                break;
            case PassengerMenuState::CHECK_IN:
                displayCheckIn();
                break;
            case PassengerMenuState::LOGOUT:
                displayLogout();
                break;
        }
    }
}
void PassengerMenu::displayLogin() {
    std::string username, password;
    std::cin.ignore();
    std::cout << "--- Passenger Login ---\n";
    std::cout << "Username: ";
    getline(std::cin, username);
    std::cout << "Password: ";
    getline(std::cin, password);
    try {
        currentPassenger = std::make_unique<Passenger>(passenger.login(username, password));
        std::cout << "Login successful! Welcome, " << currentPassenger->getName() << ".\n";
        state = PassengerMenuState::PASSENGER_MENU; 
    } catch (const std::exception &e) {
        std::cout << "Login failed: " << e.what() << "\n";
        state = PassengerMenuState::EXIT;
    }
}
void PassengerMenu::displayPassengerMenu() {
    std::cout << "--- Passenger Menu ---\n";
    std::cout << "1. Search Flights\n";
    std::cout << "2. View My Reservations\n";
    std::cout << "3. Check-In\n";
    std::cout << "4. Logout\n";

    int choice;
    choice= inputHandler.getInteger(4); // Get user input using InputHandler

    switch (choice) {
        case 1:
            state = PassengerMenuState::SEARCH_FLIGHTS;
            break;
        case 2:
            state = PassengerMenuState::VIEW_RESERVATIONS;
            break;
        case 3:
            state = PassengerMenuState::CHECK_IN;
            break;
        case 4:
            state = PassengerMenuState::LOGOUT;
            break;
        default:
            //not needed as input is validated in getInteger
            break;
    }
}

void PassengerMenu::displaySearchFlights() {
    std::cout << "--- Search Flights ---\n";
    std::cout << "Feature not implemented yet.\n";
    state = PassengerMenuState::PASSENGER_MENU;
}

void PassengerMenu::displayViewReservations() {
    std::cout << "--- View My Reservations ---\n";
    std::cout << "Feature not implemented yet.\n";
    state = PassengerMenuState::PASSENGER_MENU;
}

void PassengerMenu::displayCheckIn() {
    std::cout << "--- Check-In ---\n";
    std::cout << "Feature not implemented yet.\n";
    state = PassengerMenuState::PASSENGER_MENU;
}

void PassengerMenu::displayLogout() {
    std::cout << "Logging out. Goodbye!\n";
    state = PassengerMenuState::EXIT; // Exit the menu loop
}