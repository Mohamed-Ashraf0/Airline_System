#include "Menus/Admin_Menus.hpp"
AdminMenu::AdminMenu()
    : state(AdminMenuState::LOGIN)
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
            displayAdminMenu();
            break;
        case AdminMenuState::MANAGE_FLIGHTS:
            displayManageFlights();
            break;
        case AdminMenuState::MANAGE_AIRCRAFTS:
            displayManageAircrafts();
            break;
        case AdminMenuState::MANAGE_USERS:
            displayManageUsers();
            break;
        case AdminMenuState::MANAGE_PASSENGERS:
            displayManagePassengers();
            break;
        case AdminMenuState::MANAGE_BOOKING_AGENTS:
            displayManageBookingAgents();
            break;
        case AdminMenuState::MANAGE_PILOTS:
            displayManagePilots();
            break;
        case AdminMenuState::MANAGE_FLIGHT_ATTENDANTS:
            displayManageFlightAttendants();
            break;
        case AdminMenuState::UPDATE_FLIGHT:
            displayupdateFlight();
            break;
        case AdminMenuState::UPDATE_AIRCRAFT:
            displayupdateAircraft();
            break;
        case AdminMenuState::GENERATE_REPORTS:
            break;
        case AdminMenuState::LOGOUT:
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
        std::cout << "Login failed: Invalid username or password.\n";
        state = AdminMenuState::EXIT;
    }
}
void AdminMenu::displayLogout()
{
    std::cout << "Logging out. Goodbye!\n";
    state = AdminMenuState::EXIT;
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
        state = AdminMenuState::MANAGE_FLIGHTS;
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
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        addFlight();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    case 2:
        state = AdminMenuState::UPDATE_FLIGHT;
        break;
    case 3:
        removeFlight();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    case 4:
        viewAllFlights();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    case 5:
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    default:
        break;
    }
}
void AdminMenu::displayManageAircrafts()
{
    std::cout << "--- Manage Aircraft ---\n";
    std::cout << "1. Add New Aircraft\n";
    std::cout << "2. Update Existing Aircraft\n";
    std::cout << "3. Remove Aircraft\n";
    std::cout << "4. View All Aircraft\n";
    std::cout << "5. Back to Main Menu\n";
    int choice;
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        addAircraft();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    case 2:
        state = AdminMenuState::UPDATE_AIRCRAFT;
        break;
    case 3:
        removeAircraft();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    case 4:
        viewAllAircrafts();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    case 5:
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    default:
        // not needed as input is validated in getInteger
        break;
    }
    
}
void AdminMenu::displayManageUsers()
{
    std::cout << "--- Manage Users ---\n";
    std::cout << "1. Passenger\n";
    std::cout << "2. Booking agent\n";
    std::cout << "3. Pilot\n";
    std::cout << "4. Flight attendant\n";
    std::cout << "5. Back to Main Menu\n";
    int choice;
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        state = AdminMenuState::MANAGE_PASSENGERS;
        break;
    case 2:
        state = AdminMenuState::MANAGE_BOOKING_AGENTS;
        break;
    case 3:
        state = AdminMenuState::MANAGE_PILOTS;
        break;
    case 4:

        state = AdminMenuState::MANAGE_FLIGHT_ATTENDANTS;
        break;
    case 5:
        state = AdminMenuState::ADMINSTRATOR_MENU;
        break;
    default:
        break;
    }
}
void AdminMenu::displayManagePassengers()
{
    std::cout << "--- Manage Passengers ---\n";
    std::cout << "1. Add New Passenger\n";
    std::cout << "2. Update Existing Passenger\n";
    std::cout << "3. Remove Passenger\n";
    std::cout << "4. View All Passengers\n";
    std::cout << "5. Back to Manage Users Menu\n";
    int choice;
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        addPassenger();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 2:
        updatePassenger();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 3:
        removePassenger();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 4:
        viewAllPassengers();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 5:
        state = AdminMenuState::MANAGE_USERS;
        break;
    default:
        break;
    }
}
void AdminMenu::displayManageBookingAgents()
{
    std::cout << "--- Manage Booking Agents ---\n";
    std::cout << "1. Add New Booking Agent\n";
    std::cout << "2. Update Existing Booking Agent\n";
    std::cout << "3. Remove Booking Agent\n";
    std::cout << "4. View All Booking Agents\n";
    std::cout << "5. Back to Manage Users Menu\n";
    int choice;
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        addBookingAgent();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 2:
        updateBookingAgent();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 3:
        removeBookingAgent();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 4:
        viewAllBookingAgents();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 5:
        state = AdminMenuState::MANAGE_USERS;
        break;
    default:
        break;
    }
}
void AdminMenu::displayManagePilots()
{
    std::cout << "--- Manage Pilots ---\n";
    std::cout << "1. Add New Pilot\n";
    std::cout << "2. Update Existing Pilot\n";
    std::cout << "3. Remove Pilot\n";
    std::cout << "4. View All Pilots\n";
    std::cout << "5. Back to Manage Users Menu\n";
    int choice;
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        addPilot();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 2:
        updatePilot();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 3:
        removePilot();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 4:
        viewAllPilots();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 5:
        state = AdminMenuState::MANAGE_USERS;
        break;
    default:
        break;
    }
}
void AdminMenu::displayManageFlightAttendants()
{
    std::cout << "--- Manage Flight Attendants ---\n";
    std::cout << "1. Add New Flight Attendant\n";
    std::cout << "2. Update Existing Flight Attendant\n";
    std::cout << "3. Remove Flight Attendant\n";
    std::cout << "4. View All Flight Attendants\n";
    std::cout << "5. Back to Manage Users Menu\n";
    int choice;
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        addFlightAttendant();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 2:
        updateFlightAttendant();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 3:
        removeFlightAttendant();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 4:
        viewAllFlightAttendants();
        state = AdminMenuState::MANAGE_USERS;
        break;
    case 5:
        state = AdminMenuState::MANAGE_USERS;
        break;
    default:
        break;
    }
}
void AdminMenu::displayupdateFlight()
{
    std::cout << "--- Update Existing Flight ---\n";
    Flight flight;
    try
    {
        flight = flight_handler.chooseFlight(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        return;
    }
    std::cout << "1. Flight Details\n";
    std::cout << "2. Crew Assignments\n";
    std::cout << "3. Status\n";
    std::cout << "4. Back to Manage Flights\n";
    int choice;
    choice = inputHandler.getInteger(4);
    switch (choice)
    {
    case 1:
        updateFlight(flight);
        state = AdminMenuState::MANAGE_FLIGHTS;
        break;
    case 2:
        assignCrew(flight);
        state = AdminMenuState::MANAGE_FLIGHTS;
        break;
    case 3:
        updateFlightstatus(flight);
        state = AdminMenuState::MANAGE_FLIGHTS;
        break;
    case 4:
        state = AdminMenuState::MANAGE_FLIGHTS;
        break;
    default:
        break;
    }
}
void AdminMenu::displayupdateAircraft()
{
    std::cout << "--- Update Existing Aircraft ---\n";
    Aircraft aircraft;
    try
    {
        aircraft = aircraft_handler.chooseaircraft(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        state = AdminMenuState::ADMINSTRATOR_MENU;
        return;
    }
    std::cout << "1. Aircraft Details\n";
    std::cout << "2. Maintenance \n";
    std::cout << "3. Back to Manage Flights\n";
    int choice;
    choice = inputHandler.getInteger(3);
    switch (choice)
    {
    case 1:
        updateAircraft(aircraft);
        state = AdminMenuState::MANAGE_AIRCRAFTS;
        break;
    case 2:
        Maintenancemenu(aircraft);
        state = AdminMenuState::MANAGE_AIRCRAFTS;
        break;
    case 3:
        state = AdminMenuState::MANAGE_AIRCRAFTS;
        break;
    default:
        break;
    }
}
Flight AdminMenu::addFlight()
{
    std::string origin, destination, departureDateTime, BoardingGate, arrivalDateTime, BoardingTime, aircraftType, status;
    int cost;
    std::cin.ignore();
    std::cout << "--- Add New Flight ---\n";
    std::cout << "Enter Origin: ";
    getline(std::cin, origin);
    std::cout << "Enter Destination: ";
    getline(std::cin, destination);
    std::cout << "Enter Departure Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, departureDateTime);
    std::cout << "Enter Arrival Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, arrivalDateTime);
    std::cout << "Enter Boarding Gate: ";
    getline(std::cin, BoardingGate);
    std::cout << "Enter Boarding Time: ";
    getline(std::cin, BoardingTime);
    std::cout << "Enter Status (Scheduled/Delayed/Canceled): ";
    getline(std::cin, status);
    std::cout << "Enter Cost: ";
    cost = inputHandler.getInteger();
    Aircraft aircraft;
    try
    {
        aircraft = aircraft_handler.chooseaircraft();
    }
    catch (const std::exception &e)
    {
        if (std::string(e.what()).empty())
        {
            aircraft = addAircraft();
        }
        else
        {
            std::cerr << e.what() << "\n";
            std::cin.ignore();
            std::cout << "1. Add new Aircraft\n";
            std::cout << "2. Back to Main Menu\n";
            int choice;
            choice = inputHandler.getInteger(2);
            switch (choice)
            {
            case 1:
                aircraft = addAircraft();
                break;
            case 2:
                state = AdminMenuState::ADMINSTRATOR_MENU;
                return Flight();

                break;
            default:
                break;
            }
        }
    }
    Flight newFlight(origin, destination, departureDateTime, arrivalDateTime, aircraft.getId(), cost, aircraft.getSeatCount(), status);
    newFlight.setBoardingGate(BoardingGate);
    newFlight.setBoardingTime(BoardingTime);
    flight_handler.addFlight(newFlight);
    std::cout << "Flight " << newFlight.getId() << " has been successfully added.\n";
    return newFlight;
}
void AdminMenu::updateFlight(Flight &flight)
{
    std::cout << "--- Update Flight Details ---\n";
    std::string origin, destination, departureDateTime, arrivalDateTime, status;
    int cost;
    std::cin.ignore();

    std::cout << "Enter New Origin: ";
    getline(std::cin, origin);
    std::cout << "Enter New Destination: ";
    getline(std::cin, destination);
    std::cout << "Enter New Departure Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, departureDateTime);
    std::cout << "Enter New Arrival Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, arrivalDateTime);
    std::cout << "Enter New Cost: ";
    cost = inputHandler.getInteger();
    flight.setOrigin(origin);
    flight.setDestination(destination);
    flight.setDeparture_Date_and_Time(departureDateTime);
    flight.setArrival_Date_and_Time(arrivalDateTime);
    flight.setStatus(status);
    flight.setCost(cost);
    flight_handler.updateFlight(flight);
    std::cout << "Flight " << flight.getId() << " has been successfully updated.\n";
}
void AdminMenu::assignCrew(Flight &flight)
{
    std::cout << "--- Assign Crew to Flight ---\n";
    std::cout << "1. Assign Pilot\n";
    std::cout << "2. Assign Flight Attendant\n";
    std::cout << "3. Back to Manage Flights\n";
    int choice;
    choice = inputHandler.getInteger(3);
    switch (choice)
    {
    case 1:
        assignpilot(flight);
        break;
    case 2:
        assignflightattendant(flight);
        break;
    case 3:
        break;
    default:
        break;
    }
}
void AdminMenu::updatePassenger()
{
    std::cout << "--- Update Passenger ---\n";
    Passenger passenger;
    try
    {
        passenger = passenger_handler.choosePassenger(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    std::string username, password;
    std::cin.ignore();
    std::cout << "Enter New Username: ";
    getline(std::cin, username);
    std::cout << "Enter New Password: ";
    getline(std::cin, password);
    passenger.setUsername(username);
    passenger.setPassword(password);
    passenger_handler.updatePassenger(passenger);
    std::cout << "Passenger " << passenger.getId() << " has been successfully updated.\n";
}
void AdminMenu::assignpilot(Flight &flight)
{
    std::cout << "--- Assign Pilot to Flight ---\n";
    Pilot pilot;
    try
    {
        pilot = pilot_handler.choosePilot(REMOVE_ADD_OPTION, flight.getPilots());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    pilot.addFlightId(flight.getId());
    flight.addPilot(pilot.getId());
    flight_handler.updateFlight(flight);
    pilot_handler.updatePilot(pilot);
    std::cout << "Pilot " << pilot.getId() << " has been successfully assigned to Flight " << flight.getId() << ".\n";
}
void AdminMenu::assignflightattendant(Flight &flight)
{
    std::cout << "--- Assign Flight Attendant to Flight ---\n";
    FlightAttendant attendant;
    try
    {
        attendant = flight_attendant_handler.chooseFlightAttendant(REMOVE_ADD_OPTION, flight.getFlightAttendants());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    attendant.addFlightId(flight.getId());
    flight.addFlightAttendant(attendant.getId());
    flight_handler.updateFlight(flight);
    flight_attendant_handler.updateFlightAttendant(attendant);
    std::cout << "Flight Attendant " << attendant.getId() << " has been successfully assigned to Flight " << flight.getId() << ".\n";
}
void AdminMenu::updateFlightstatus(Flight &flight)
{
    std::cout << "--- Update Flight Status ---\n";
    std::string status;
    std::cin.ignore();

    std::cout << "Enter New Status (Scheduled/Delayed/Canceled): ";
    getline(std::cin, status);
    flight.setStatus(status);
    flight_handler.updateFlight(flight);
    std::cout << "Flight " << flight.getId() << " has been successfully updated.\n";
}
void AdminMenu::viewAllFlights()
{
    std::cout << "--- View All Flights ---\n";
    try
    {
        flight_handler.viewAllFlights();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
    }
}
void AdminMenu::removeFlight()
{
    Flight flight;
    std::cout << "--- Remove Flight ---\n";
    try
    {
        flight = flight_handler.chooseFlight(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    flight_handler.removeFlight(flight);
    std::cout << "Flight " << flight.getId() << " has been successfully removed.\n";
}
Aircraft AdminMenu::addAircraft()
{
    std::string aircraftType;
    int totalSeats;
    std::cin.ignore();
    std::cout << "--- Add New Aircraft ---\n";
    std::cout << "Enter Aircraft Type: ";
    getline(std::cin, aircraftType);
    std::cout << "Enter Total Seats: ";
    totalSeats = inputHandler.getInteger();
    Aircraft aircraft(aircraftType, totalSeats);
    aircraft_handler.addaircraft(aircraft);
    std::cout << "Aircraft " << aircraft.getId() << " has been successfully added.\n";
    return aircraft;
}
void AdminMenu::updateAircraft(Aircraft &aircraft)
{
    std::cout << "--- Update Aircraft Details ---\n";
    std::string aircraftType;
    int totalSeats;
    std::cin.ignore();

    std::cout << "Enter New Aircraft Type: ";
    getline(std::cin, aircraftType);
    std::cout << "Enter New Total Seats: ";
    totalSeats = inputHandler.getInteger();
    aircraft.setType(aircraftType);
    aircraft.setSeatCount(totalSeats);
    aircraft_handler.updateaircraft(aircraft);
    std::cout << "Aircraft " << aircraft.getId() << " has been successfully updated.\n";
}
void AdminMenu::removeAircraft()
{
    Aircraft aircraft;
    std::cout << "--- Remove Aircraft ---\n";
    try
    {
        aircraft = aircraft_handler.chooseaircraft(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    aircraft_handler.removeaircraft(aircraft);
    std::cout << "Aircraft " << aircraft.getId() << " has been successfully removed.\n";
}
void AdminMenu::viewAllAircrafts()
{
    std::cout << "--- View All Aircrafts ---\n";
    try
    {
        aircraft_handler.viewAllaircrafts();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
}
void AdminMenu::addPassenger()
{
    std::string name, email, username, password;
    std::cin.ignore();
    std::cout << "--- Add New Passenger ---\n";
    std::cout << "Enter Username: ";
    getline(std::cin, username);
    std::cout << "Enter Password: ";
    getline(std::cin, password);
    Passenger passenger(username, password);
    try
    {
        passenger_handler.addPassenger(passenger);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    std::cout << "Passenger " << passenger.getId() << " has been successfully added.\n";
}
void AdminMenu::removePassenger()
{
    Passenger passenger;
    std::cout << "--- Remove Passenger ---\n";
    try
    {
        passenger = passenger_handler.choosePassenger(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    passenger_handler.deletePassenger(passenger.getId());
    std::cout << "Passenger " << passenger.getId() << " has been successfully removed.\n";
}
void AdminMenu::viewAllPassengers()
{
    std::cout << "--- View All Passengers ---\n";
    try
    {
        passenger_handler.viewAllPassengers();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
    }
}
void AdminMenu::addBookingAgent()
{
    std::string name, username, password;
    std::cin.ignore();
    std::cout << "--- Add New Booking Agent ---\n";
    std::cout << "Enter Username: ";
    getline(std::cin, username);
    std::cout << "Enter Password: ";
    getline(std::cin, password);
    BookingAgent agent(username, password);
    try
    {
        booking_agent_handler.addBookingAgent(agent);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    std::cout << "Booking Agent " << agent.getId() << " has been successfully added.\n";
}
void AdminMenu::updateBookingAgent()
{
    std::cout << "--- Update Booking Agent ---\n";
    BookingAgent agent;
    try
    {
        agent = booking_agent_handler.chooseBookingAgent(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    std::string name, username, password;
    std::cin.ignore();

    std::cout << "Enter New Username: ";
    getline(std::cin, username);
    std::cout << "Enter New Password: ";
    getline(std::cin, password);
    agent.setUsername(username);
    agent.setPassword(password);
    booking_agent_handler.updateBookingAgent(agent);
    std::cout << "Booking Agent " << agent.getId() << " has been successfully updated.\n";
}
void AdminMenu::removeBookingAgent()
{
    BookingAgent agent;
    std::cout << "--- Remove Booking Agent ---\n";
    try
    {
        agent = booking_agent_handler.chooseBookingAgent(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    booking_agent_handler.deleteBookingAgent(agent.getId());
    std::cout << "Booking Agent " << agent.getId() << " has been successfully removed.\n";
}
void AdminMenu::viewAllBookingAgents()
{
    std::cout << "--- View All Booking Agents ---\n";
    try
    {
        booking_agent_handler.viewAllBookingAgents();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
    }
}
Pilot AdminMenu::addPilot()
{
    std::string name, licenseNumber;
    std::cin.ignore();
    std::cout << "--- Add New Pilot ---\n";
    std::cout << "Enter Name: ";
    getline(std::cin, name);
    Pilot pilot(name);
    pilot_handler.addPilot(pilot);
    std::cout << "Pilot " << pilot.getId() << " has been successfully added.\n";
    return pilot;
}
void AdminMenu::updatePilot()
{
    Pilot pilot;
    std::cout << "--- Update Pilot ---\n";
    try
    {
        pilot = pilot_handler.choosePilot(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    std::string name, licenseNumber;
    std::cin.ignore();

    std::cout << "Enter New Name: ";
    getline(std::cin, name);
    pilot.setName(name);
    pilot_handler.updatePilot(pilot);
    std::cout << "Pilot " << pilot.getId() << " has been successfully updated.\n";
}
void AdminMenu::removePilot()
{
    Pilot pilot;
    std::cout << "--- Remove Pilot ---\n";
    try
    {
        pilot = pilot_handler.choosePilot(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    pilot_handler.deletePilot(pilot.getId());
    std::cout << "Pilot " << pilot.getId() << " has been successfully removed.\n";
}
void AdminMenu::viewAllPilots()
{
    std::cout << "--- View All Pilots ---\n";
    try
    {
        pilot_handler.viewAllPilots();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
    }
}
FlightAttendant AdminMenu::addFlightAttendant()
{
    std::string name;
    std::cin.ignore();
    std::cout << "--- Add New Flight Attendant ---\n";
    std::cout << "Enter Name: ";
    getline(std::cin, name);
    FlightAttendant attendant(name);
    flight_attendant_handler.addFlightAttendant(attendant);
    std::cout << "Flight Attendant " << attendant.getId() << " has been successfully added.\n";
    return attendant;
}
void AdminMenu::updateFlightAttendant()
{
    std::cout << "--- Update Flight Attendant ---\n";
    FlightAttendant attendant;
    try
    {
        attendant = flight_attendant_handler.chooseFlightAttendant(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    std::string name;
    std::cin.ignore();
    std::cout << "Enter New Name: ";
    getline(std::cin, name);
    attendant.setName(name);
    flight_attendant_handler.updateFlightAttendant(attendant);
    std::cout << "Flight Attendant " << attendant.getId() << " has been successfully updated.\n";
}
void AdminMenu::removeFlightAttendant()
{
    FlightAttendant attendant;
    std::cout << "--- Remove Flight Attendant ---\n";
    try
    {
        attendant = flight_attendant_handler.chooseFlightAttendant(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    flight_attendant_handler.deleteFlightAttendant(attendant.getId());
    std::cout << "Flight Attendant " << attendant.getId() << " has been successfully removed.\n";
}
void AdminMenu::viewAllFlightAttendants()
{
    std::cout << "--- View All Flight Attendants ---\n";
    try
    {
        flight_attendant_handler.viewAllFlightAttendants();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
    }
}
void AdminMenu::Maintenancemenu(Aircraft &aircraft)
{
    std::cout << "--- Aircraft Maintenance ---\n";
    std::cout << "1. Add Maintenance\n";
    std::cout << "2. Update Maintenance\n";
    std::cout << "3. View Aircraft Maintenances\n";
    std::cout << "4. Remove Maintenance\n";
    std::cout << "5. Back to Manage Aircraft\n";
    int choice;
    choice = inputHandler.getInteger(5);
    switch (choice)
    {
    case 1:
        addMaintenance(aircraft);
        break;
    case 2:
        updateMaintenance(aircraft);
        break;
    case 3:
        viewallMaintenance(aircraft);
        break;
    case 4:
        removeMaintenance(aircraft);
        break;
    case 5:
        state = AdminMenuState::MANAGE_AIRCRAFTS;
        break;
    default:
        break;
    }
}
void AdminMenu::addMaintenance(Aircraft &aircraft)
{
    std::string date, details;
    std::cin.ignore();
    std::cout << "--- Add Maintenance ---\n";
    std::cout << "Enter Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, date);
    std::cout << "Enter Details: ";
    getline(std::cin, details);
    Maintenance maintenance(date, aircraft.getId(), details);
    maintenance_handler.addMaintenance(maintenance);
    aircraft.addMaintenance(maintenance.getId());
    aircraft_handler.updateaircraft(aircraft);
    std::cout << "Maintenance " << maintenance.getId() << " has been successfully added to Aircraft " << aircraft.getId() << ".\n";
}
void AdminMenu::removeMaintenance(Aircraft &aircraft)
{
    Maintenance maintenance;
    Flight flight;
    try
    {
        maintenance = maintenance_handler.chooseMaintenance(REMOVE_ADD_OPTION, aircraft.getMaintenance());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    maintenance_handler.removeMaintenance(maintenance.getId());
    std::cout << "Maintenance " << maintenance.getId() << " has been successfully removed" << ".\n";
}
void AdminMenu::viewallMaintenance(Aircraft &aircraft)
{
    std::cout << "--- View Aircraft Maintenance ---\n";
    try
    {
        maintenance_handler.viewmyMaintenances(aircraft.getMaintenance());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
    }
}
void AdminMenu::updateMaintenance(Aircraft &aircraft)
{
    Maintenance maintenance;
    try
    {
        maintenance = maintenance_handler.chooseMaintenance(REMOVE_ADD_OPTION, aircraft.getMaintenance());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return;
    }
    std::string date, details;
    std::cin.ignore();

    std::cout << "Enter New Date and Time (YYYY-MM-DD HH:MM): ";
    getline(std::cin, date);
    std::cout << "Enter New Details: ";
    getline(std::cin, details);
    maintenance.setDate(date);
    maintenance.setDetails(details);
    try
    {
        maintenance_handler.updateMaintenance(maintenance);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    std::cout << "Maintenance " << maintenance.getId() << " has been successfully updated.\n";
}