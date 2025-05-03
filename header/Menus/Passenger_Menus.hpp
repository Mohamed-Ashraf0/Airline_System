#ifndef PASSENGER_MENUS_HPP
#define PASSENGER_MENUS_HPP

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Handlers/input_Handler.hpp"
#include "Handlers/Passenger_Handler.hpp"
#include "Handlers/Payment_method_Handler.hpp"
#include "Handlers/Flight_Handler.hpp"
#include "Handlers/Reservation_Handler.hpp"
#include "Handlers/Boarding_Handler.hpp"
#include "Entities/Passenger.hpp"
#include "Entities/Flight.hpp"
#include "Entities/Reservation.hpp"
#include "Entities/Payment_method.hpp"
#include "Entities/Boarding.hpp"
#include "Menus/Menu.hpp"
enum class PassengerMenuState
{
    LOGIN,
    PASSENGER_MENU,
    BOOK_FLIGHT,
    VIEW_RESERVATIONS,
    CHECK_IN,
    MANAGE_PAYMENT_METHOD,
    LOGOUT,
    EXIT
};

class PassengerMenu : public Menu
{
private:
    PassengerMenuState state;
    paymentmethodhandler payment_method_handler;
    InputHandler inputHandler;
    passengerhandler passenger_handler;
    flighthandler flight_handler;
    reservationHandler reservation_handler;
    boardinghandler boarding_handler;
    std::unique_ptr<Passenger> currentPassenger;
    void displayLogin();
    void displayPassengerMenu();
    void displayManagePaymentMethodMenu();
    PaymentMethod addPaymentMethod();
    void updatePaymentMethod();
    void viewTransactions();
    void removePaymentMethod();
    void displayBookFlight();
    void displayViewReservations();
    void displayCheckIn();
    void displayLogout();

public:
    PassengerMenu();
    void displayMenu();
};

#endif