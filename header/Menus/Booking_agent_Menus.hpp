#ifndef BOOKING_AGENT_MENUS_HPP
#define BOOKING_AGENT_MENUS_HPP

#include <iostream>
#include <string>
#include <memory>
#include "Handlers/input_Handler.hpp"
#include "Handlers/Booking_agent_Handler.hpp"
#include "Handlers/Passenger_Handler.hpp"
#include "Handlers/Flight_Handler.hpp"
#include "Handlers/Payment_method_Handler.hpp"
#include "Handlers/Reservation_Handler.hpp"
#include "Entities/Booking_agent.hpp"
#include "Entities/Flight.hpp"
#include "Entities/Passenger.hpp"
#include "Entities/Payment_method.hpp"
#include "Entities/Reservation.hpp"
#include "Menus/Menu.hpp"
enum class BookingAgentMenuState
{
    LOGIN,
    BOOKING_AGENT_MENU,
    VIEW_ALL_FLIGHTS,
    BOOK_FLIGHT,
    MODIFY_RESERVATION,
    CANCEL_RESERVATION,
    LOGOUT,
    EXIT
};

class BookingAgentMenu : public Menu
{
private:
    BookingAgentMenuState state;
    InputHandler inputHandler;
    bookingagenthandler booking_agent_handler;
    passengerhandler passenger_handler;
    paymentmethodhandler payment_method_handler;
    reservationHandler reservation_handler;
    flighthandler flight_handler;
    std::unique_ptr<BookingAgent> currentagent;
    void displayLogin();
    void displayBookingAgentMenu();
    void displayLogout();
    void displayViewAllFlights();
    void displayBookFlight();
    void displayModifyReservation();
    void displayCancelReservation();
    PaymentMethod addPaymentMethod(Passenger &passenger);
public:
    BookingAgentMenu();
    void displayMenu();
};

#endif