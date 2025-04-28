#include "Menus/Admin_Menus.hpp"
AdminMenu::AdminMenu()
    : state(AdminMenuState::LOGIN), inputHandler(), passenger(), currentPassenger(nullptr)
{
}
void AdminMenu::displayMenu()
{
    while (state != AdminMenuState::EXIT)
    {
        switch (state)
        {
        case AdminMenuState::LOGIN:
            displayLogin();
            break;
        case AdminMenuState::ADMINSTRATOR_MENU:
            displayPassengerMenu();
            break;
        case AdminMenuState::MANAGE_FLIGHTS:
            displaySearchFlights();
            break;
        case AdminMenuState::MANAGE_AIRCRAFTS:
            displayViewReservations();
            break;
        case AdminMenuState::MANAGE_USERS:
            displayCheckIn();
            break;
        case AdminMenuState::GENERATE_REPORTS:
            displayCheckIn();
            break;
        case AdminMenuState::LOGOUT:
            displayCheckIn();
            break;
        case AdminMenuState::EXIT:
            displayLogout();
            break;
        }
    }
}
void AdminMenu::displayLogin()
{
    std::string username, password;
    std::cin.ignore();
    std::cout << "--- Administrator Login ---\n";
    std::cout << "Username: ";
    getline(std::cin, username);
    std::cout << "Password: ";
    getline(std::cin, password);
    if (username == "admin" && password == "admin")
    {
        std::cout << "Login successful! Welcome, admin.\n";
        state = AdminMenuState::ADMINSTRATOR_MENU;
    }
    else
    {
        std::cout << "Login failed: Invalid credentials.\n";
        state = AdminMenuState::EXIT;
    }
}
void AdminMenu::displayAdminMenu()
{
    std::cout << "--- Administrator Menu ---\n";
    std::cout << "1. Manage Flights\n";
    std::cout << "2. Manage Aircraft\n";
    std::cout << "3. Manage Users\n";
    std::cout << "4. Generate Reports\n";
    std::cout << "5. Logout\n";

    int choice;
    choice = inputHandler.getInteger(5); // Get user input using InputHandler

    switch (choice)
    {
    case 1:
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    case 2:
        state = AdminMenuState::MANAGE_AIRCRAFTS;
        break;
    case 3:
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 4:
        state = AdminMenuState::GENERATE_REPORTS;
        break;
    case 5:
        state = AdminMenuState::LOGOUT;
        break;
    default:
        // not needed as input is validated in getInteger
        break;
    }
}

void AdminMenu::displayManageFlights()
{
    std::cout << "--- Manage Flights ---\n";
    std::cout << "1. Add New Flight\n";
    std::cout << "2. Update Existing Flight\n";
    std::cout << "3. Remove Flight\n";
    std::cout << "4. View All Flights\n";
    std::cout << "5. Back to Main Menu\n";
    int choice;
    choice = inputHandler.getInteger(5); // Get user input using InputHandler

    switch (choice)
    {
    case 1:
        addFlight();
        break;
    case 2:
        state = AdminMenuState::MANAGE_AIRCRAFTS;
        break;
    case 3:
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 4:
        state = AdminMenuState::GENERATE_REPORTS;
        break;
    case 5:
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    default:
        // not needed as input is validated in getInteger
        break;
    }
}

void AdminMenu::addFlight()
{
    std::string  origin, destination, departureDateTime, arrivalDateTime, aircraftType, status;
    int totalSeats, cost;
    std::cin.ignore();
    getline(std::cin, origin);
    std::cout << "Enter Destination: ";
    getline(std::cin, destination);
    std::cout << "Enter Departure Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, departureDateTime);
    std::cout << "Enter Arrival Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, arrivalDateTime);
    std::cout << "Enter Aircraft Type: ";
    getline(std::cin, aircraftType);
    std::cout << "Enter Total Seats: ";
    totalSeats = inputHandler.getInteger();
    std::cout << "Enter Status (Scheduled/Delayed/Canceled): ";
    std::cout << "Enter Cost: ";
    cost = inputHandler.getInteger();
    getline(std::cin, status);
    Aircraft aircraft;
    try
    {
        aircraft = aircraft_handler.search_aircraft(aircraftType, totalSeats);
    }
    catch (const std::exception &e)
    {
        aircraft.settype(aircraftType);
        aircraft.setSeatCount(totalSeats);
        aircraft_handler.addaircraft(aircraft);
    }
    Flight newFlight(origin, destination, departureDateTime, arrivalDateTime, aircraft.getid(), cost);
    newFlight.setStatus(status == "Scheduled" ? FlightStatus::SCHEDULED : status == "Delayed" ? FlightStatus::DELAYED
                                                                                              : FlightStatus::CANCELLED);
    flight_handler.addFlight(newFlight);

    std::cout << "Flight " << newFlight.getId() << " has been successfully added to the schedule.\n";

    state = AdminMenuState::ADMINSTRATOR_MENU;
}

void PassengerMenu::displayCheckIn()
{
    std::cout << "--- Check-In ---\n";
    std::cout << "Feature not implemented yet.\n";
    state = PassengerMenuState::PASSENGER_MENU;
}

void PassengerMenu::displayLogout()
{
    std::cout << "Logging out. Goodbye!\n";
    state = PassengerMenuState::EXIT; // Exit the menu loop
}