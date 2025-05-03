#include "Menus/Booking_agent_Menus.hpp"
BookingAgentMenu::BookingAgentMenu()
    : state(BookingAgentMenuState::LOGIN)
{}
void BookingAgentMenu::displayMenu() {
    while (state != BookingAgentMenuState::EXIT) { 
        switch (state) {
            case BookingAgentMenuState::LOGIN:
                displayLogin();
                break;
            case BookingAgentMenuState::BOOKING_AGENT_MENU:
                displayBookingAgentMenu();
                break;
            case BookingAgentMenuState::SEARCH_FLIGHTS:
                displaySearchFlights(); 
                break;
            case BookingAgentMenuState::BOOK_FLIGHT:
                displayBookFlight();    
                break;
            case BookingAgentMenuState::MODIFY_RESERVATION:
                displayModifyReservation(); 
                break;
            case BookingAgentMenuState::CANCEL_RESERVATION:
                displayCancelReservation(); 
                break;
            case BookingAgentMenuState::LOGOUT:
                displayLogout();
                break;
        }
    }
}
void BookingAgentMenu::displayLogin() {
    std::string username, password;
    std::cin.ignore();
    std::cout << "--- Booking Agent Login ---\n";
    std::cout << "Username: ";
    getline(std::cin, username);
    std::cout << "Password: ";
    getline(std::cin, password);
    try {
        currentagent = std::make_unique<BookingAgent>(booking_agent_handler.login(username, password));
        std::cout << "Login successful! Welcome, " << currentagent->getUsername() << ".\n";
        state = BookingAgentMenuState::BOOKING_AGENT_MENU; 
    } catch (const std::exception &e) {
        std::cout << "Login failed: " << e.what() << "\n";
        state =  BookingAgentMenuState::EXIT;
    }
}
void BookingAgentMenu::displayLogout() {
    std::cout << "Logging out. Goodbye!\n";
    state = BookingAgentMenuState::EXIT;
}
void BookingAgentMenu::displayBookingAgentMenu() {
    std::cout << "--- Booking Agent Menu ---\n";
    std::cout << "1. Search Flights\n";
    std::cout << "2. Book Flight\n";
    std::cout << "3. Modify Reservation\n";
    std::cout << "4. Cancel Reservation\n";
    std::cout << "5. Logout\n";

    int choice;
    choice= inputHandler.getInteger(5);

    switch (choice) {
        case 1:
            state = BookingAgentMenuState::SEARCH_FLIGHTS;
            break;
        case 2:
            state = BookingAgentMenuState::BOOK_FLIGHT;
            break;
        case 3:
            state = BookingAgentMenuState::MODIFY_RESERVATION;
            break;
        case 4:
            state = BookingAgentMenuState::CANCEL_RESERVATION;
            break;
        case 5:
            state = BookingAgentMenuState::LOGOUT;
            break;
        default:

            break;
    }
}
void BookingAgentMenu::displaySearchFlights() {
    std::cout << "--- Search Flights ---\n";
    state = BookingAgentMenuState::BOOKING_AGENT_MENU; 
}
void BookingAgentMenu::displayBookFlight() {
    std::cout << "--- Book Flight ---\n";
    state = BookingAgentMenuState::BOOKING_AGENT_MENU; 
}
void BookingAgentMenu::displayModifyReservation() {
    std::cout << "--- Modify Reservation ---\n";
    state = BookingAgentMenuState::BOOKING_AGENT_MENU; 
}
void BookingAgentMenu::displayCancelReservation() {
    std::cout << "--- Cancel Reservation ---\n";
    state = BookingAgentMenuState::BOOKING_AGENT_MENU; 
}
