#ifndef BOOKING_AGENT_MENUS_HPP
#define BOOKING_AGENT_MENUS_HPP

#include <iostream>
#include <string>
#include <memory>
#include "Handlers/input_Handler.hpp"
#include "Handlers/Booking_agent_Handler.hpp"
#include "Entities/Booking_agent.hpp"
#include "Menus/Menu.hpp"
enum class BookingAgentMenuState
{
    LOGIN,
    BOOKING_AGENT_MENU,
    SEARCH_FLIGHTS,
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
    std::unique_ptr<BookingAgent> currentagent;
    void displayLogin();
    void displayBookingAgentMenu();
    void displayLogout();
    void displaySearchFlights();
    void displayBookFlight();
    void displayModifyReservation();
    void displayCancelReservation();
public:
    BookingAgentMenu();
    void displayMenu();
};

#endif