#ifndef PASSENGER_MENUS_HPP
#define PASSENGER_MENUS_HPP

#include <iostream>
#include <string>
#include <memory>
#include "Handlers/input_Handler.hpp"
#include "Handlers/Passenger_Handler.hpp"
#include "Handlers/Flight_Handler.hpp"
#include "Handlers/Aircraft_Handler.hpp"
#include "Entities/Passenger.hpp"
#include "Entities/Flight.hpp"
#include "Entities/Aircraft.hpp"
#include "Menus/Menu.hpp"
enum class AdminMenuState
{
    LOGIN,
    ADMINSTRATOR_MENU,
    MANAGE_FLIGHTS,
    MANAGE_AIRCRAFTS,
    MANAGE_USERS,
    GENERATE_REPORTS,
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
    void displayMenu();
    void displayLogin();
    void displayAdminMenu();
    void displayManageFlights();
    void addFlight();
    void displayManageAircrafts();
    void displayManageUsers();
    void displayGenerateReports();

public:
    AdminMenu();

};

#endif