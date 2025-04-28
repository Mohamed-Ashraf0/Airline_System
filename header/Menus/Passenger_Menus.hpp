#ifndef PASSENGER_MENUS_HPP
#define PASSENGER_MENUS_HPP

#include <iostream>
#include <string>
#include <memory>
#include "Handlers/input_Handler.hpp"
#include "Handlers/Passenger_Handler.hpp"
#include "Entities/Passenger.hpp"
#include "Menus/Menu.hpp"
enum class PassengerMenuState
{
    LOGIN,
    PASSENGER_MENU,
    SEARCH_FLIGHTS,
    VIEW_RESERVATIONS,
    CHECK_IN,
    LOGOUT,
    EXIT
};

class PassengerMenu : public Menu
{
private:
    PassengerMenuState state;
    InputHandler inputHandler;
    passengerhandler passenger;
    std::unique_ptr<Passenger> currentPassenger;
    void displayMenu();
    void displayLogin();
    void displayPassengerMenu();
    void displaySearchFlights();
    void displayViewReservations();
    void displayCheckIn();
    void displayLogout();

public:
    PassengerMenu();

};

#endif