#ifndef ADMIN_MENUS_HPP
#define ADMIN_MENUS_HPP

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include "Handlers/input_Handler.hpp"
#include "Handlers/Passenger_Handler.hpp"
#include "Handlers/Flight_Handler.hpp"
#include "Handlers/Aircraft_Handler.hpp"
#include "Entities/Passenger.hpp"
#include "Entities/Flight.hpp"
#include "Entities/Aircraft.hpp"
#include "Entities/Maintenance.hpp"
#include "Menus/Menu.hpp"
#include "Handlers/Booking_agent_Handler.hpp"
#include "Handlers/Pilot_Handler.hpp"
#include "Handlers/Flight_attendants_Handler.hpp"
#include "Handlers/Maintenance_Handler.hpp"
#include "serializers/Flight_Serializer.hpp"

enum class AdminMenuState
{
    LOGIN,
    ADMINSTRATOR_MENU,
    MANAGE_FLIGHTS,
    UPDATE_FLIGHT,
    MANAGE_AIRCRAFTS,
    UPDATE_AIRCRAFT,
    MANAGE_USERS,
    GENERATE_REPORTS,
    MANAGE_PASSENGERS,
    MANAGE_BOOKING_AGENTS,
    MANAGE_PILOTS,
    MANAGE_FLIGHT_ATTENDANTS,
    LOGOUT,
    EXIT
};

class AdminMenu : public Menu
{
private:
    AdminMenuState state;
    InputHandler inputHandler;
    passengerhandler passenger_handler;
    flighthandler flight_handler;
    aircrafthandler aircraft_handler;
    bookingagenthandler booking_agent_handler;
    pilothandler pilot_handler; 
    flightattendantshandler flight_attendant_handler;
    maintenancehandler maintenance_handler;
    void displayLogin();
    void displayLogout();
    void displayAdminMenu();
    void displayManageFlights();
    void displayManageAircrafts();
    void displayManageUsers();
    void displayManagePassengers();
    void displayManageBookingAgents();
    void displayManagePilots();
    void displayManageFlightAttendants();
    void displayupdateFlight();
    void displayupdateAircraft();
    void displayGenerateReports();

    Flight addFlight();
    void updateFlight(Flight& flight);
    void assignCrew(Flight& flight);
    void updateFlightstatus(Flight& flight);
    void removeFlight();
    void viewAllFlights();
    void assignpilot(Flight& flight);
    void assignflightattendant(Flight& flight);
    Aircraft addAircraft();
    void updateAircraft(Aircraft& aircraft);
    void Maintenancemenu(Aircraft& aircraft);
    void addMaintenance(Aircraft& aircraft);
    void removeMaintenance(Aircraft& aircraft);
    void updateMaintenance(Aircraft& aircraft);
    void viewallMaintenance(Aircraft& aircraft);
    void removeAircraft();
    void viewAllAircrafts();
    void addPassenger();
    void updatePassenger();
    void removePassenger();
    void viewAllPassengers();
    void addBookingAgent();
    void updateBookingAgent();
    void removeBookingAgent();
    void viewAllBookingAgents();
    Pilot addPilot();
    void updatePilot(); 
    void removePilot();
    void viewAllPilots();
    FlightAttendant addFlightAttendant();
    void updateFlightAttendant();
    void removeFlightAttendant();
    void viewAllFlightAttendants();
    void operationalreport();
    void maintenancereport();
    void useractivityreport();
public:
    AdminMenu();
    void displayMenu();
};

#endif