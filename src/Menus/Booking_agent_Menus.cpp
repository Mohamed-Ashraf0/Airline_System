#include "Menus/Booking_agent_Menus.hpp"
BookingAgentMenu::BookingAgentMenu()
    : state(BookingAgentMenuState::LOGIN)
{
}
void BookingAgentMenu::displayMenu()
{
    while (state != BookingAgentMenuState::EXIT)
    {
        switch (state)
        {
        case BookingAgentMenuState::LOGIN:
            displayLogin();
            break;
        case BookingAgentMenuState::BOOKING_AGENT_MENU:
            displayBookingAgentMenu();
            break;
        case BookingAgentMenuState::VIEW_ALL_FLIGHTS:
            displayViewAllFlights();
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
void BookingAgentMenu::displayLogin()
{
    std::string username, password;
    std::cin.ignore();
    std::cout << "--- Booking Agent Login ---\n";
    std::cout << "Username: ";
    getline(std::cin, username);
    std::cout << "Password: ";
    getline(std::cin, password);
    try
    {
        currentagent = std::make_unique<BookingAgent>(booking_agent_handler.login(username, password));
        std::cout << "Login successful! Welcome, " << currentagent->getUsername() << ".\n";
        state = BookingAgentMenuState::BOOKING_AGENT_MENU;
    }
    catch (const std::exception &e)
    {
        std::cout << "Login failed: " << e.what() << "\n";
        state = BookingAgentMenuState::EXIT;
    }
}
void BookingAgentMenu::displayLogout()
{
    std::cout << "Logging out. Goodbye!\n";
    state = BookingAgentMenuState::EXIT;
}
void BookingAgentMenu::displayBookingAgentMenu()
{
    std::cout << "--- Booking Agent Menu ---\n";
    std::cout << "1. View all Flights\n";
    std::cout << "2. Book Flight\n";
    std::cout << "3. Modify Reservation\n";
    std::cout << "4. Cancel Reservation\n";
    std::cout << "5. Logout\n";

    int choice;
    choice = inputHandler.getInteger(5);

    switch (choice)
    {
    case 1:
        state = BookingAgentMenuState::VIEW_ALL_FLIGHTS;
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
void BookingAgentMenu::displayViewAllFlights()
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
    state = BookingAgentMenuState::BOOKING_AGENT_MENU;
}
void BookingAgentMenu::displayBookFlight()
{
    std::cout << "--- Book Flight ---\n";
    Passenger passenger;
    Flight flight;
    PaymentMethod payment_method;
    try
    {
        passenger = passenger_handler.choosePassenger(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        state = BookingAgentMenuState::BOOKING_AGENT_MENU;
        return;
    }
    try
    {
        flight = flight_handler.chooseFlight(REMOVE_ADD_OPTION, passenger.getId());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        state = BookingAgentMenuState::BOOKING_AGENT_MENU;
        return;
    }
    if (passenger.getPaymentMethod() == "")
    {
        std::cout << "Passenger have no payment method available.\n";
        std::cin.ignore();
        std::cout << "1. Add new Payment Method\n";
        std::cout << "2. Back to Main Menu\n";
        int choice;
        choice = inputHandler.getInteger(2);
        switch (choice)
        {
        case 1:
            payment_method = addPaymentMethod(passenger);
            break;
        case 2:
            state = BookingAgentMenuState::BOOKING_AGENT_MENU;
            return;
            break;
        default:
            break;
        }
    }
    else
    {
        try
        {
            payment_method = payment_method_handler.getPaymentMethodById(passenger.getPaymentMethod());
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what();
            state = BookingAgentMenuState::BOOKING_AGENT_MENU;
            return;
        }
    }
    flight.displaySeats();
    std::string seat;
    std::cin.ignore();
    do
    {
        std::cout << "Enter seat number: " << std::flush;
        std::getline(std::cin, seat);
    } while (!flight.bookSeat(seat));
    flight.addPassenger(passenger.getId());
    std::string withdrawalDescription = "Cost for flight with ID " + flight.getId() + ": $" + std::to_string(flight.getCost());
    payment_method.addWithdrawl(withdrawalDescription);
    Reservation reservation(flight.getId(), passenger.getId(), payment_method.getId());
    reservation.setSeat(seat);
    reservation.setStatus("Booked");
    reservation_handler.addReservation(reservation);
    passenger.addReservation(reservation.getId());
    flight_handler.updateFlight(flight);
    passenger_handler.updatePassenger(passenger);
    payment_method_handler.updatePaymentMethod(payment_method);
    std::cout << "Reservation " << reservation.getId() << " has been successfully created.\n";
    state = BookingAgentMenuState::BOOKING_AGENT_MENU;
}
PaymentMethod BookingAgentMenu::addPaymentMethod(Passenger &passenger)
{
    PaymentMethod payment_method;
    std::cout << "--- Add Payment Method ---\n";
    if (passenger.getPaymentMethod() != "")
    {
        std::cout << "Passenger already has a payment method.\n";
        return payment_method;
    }
    std::string method, details;
    std::cout << "Enter Payment Method: ";
    std::cin.ignore();
    getline(std::cin, method);
    std::cout << "Enter Payment Details: ";
    getline(std::cin, details);
    payment_method.setMethod(method);
    payment_method.setDetails(details);
    payment_method_handler.addPaymentMethod(payment_method);
    passenger.setPaymentMethod(payment_method.getId());
    passenger_handler.updatePassenger(passenger);
    std::cout << "Payment method " << payment_method.getId() << " has been successfully added.\n";
    return payment_method;
}
void BookingAgentMenu::displayModifyReservation()
{
    std::cout << "--- Modify Reservation ---\n";
    Reservation reservation;
    Flight flight;
    Passenger passenger;
    try
    {
        reservation = reservation_handler.chooseReservation(REMOVE_ADD_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        state = BookingAgentMenuState::BOOKING_AGENT_MENU;
        return;
    }
    flight = flight_handler.getFlightById(reservation.getFlightId());
    flight.dropSeat(reservation.getSeat());
    flight.displaySeats();
    std::string seat,status;
    std::cin.ignore();
    do
    {
        std::cout << "Enter new seat number: " << std::flush;
        std::getline(std::cin, seat);
    } while (!flight.bookSeat(seat));
    reservation.setSeat(seat);
    reservation_handler.updateReservation(reservation);
    flight_handler.updateFlight(flight);
    std::cout << "Reservation " << reservation.getId() << " has been successfully modified.\n";
    state = BookingAgentMenuState::BOOKING_AGENT_MENU;
}
void BookingAgentMenu::displayCancelReservation()
{
    std::cout << "--- Cancel Reservation ---\n";
    Reservation reservation;
    Flight flight;
    PaymentMethod payment_method;
    try
    {
        reservation = reservation_handler.chooseReservation(REMOVE_ADD_OPTION, REMOVE_CANCLED_OPTION);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        state = BookingAgentMenuState::BOOKING_AGENT_MENU;
        return;
    }
    flight = flight_handler.getFlightById(reservation.getFlightId());
    payment_method = payment_method_handler.getPaymentMethodById(reservation.getPaymentMethodId());
    flight.removePassenger(reservation.getPassengerId());
    flight.dropSeat(reservation.getSeat());
    reservation.setStatus("Cancelled");
    payment_method.addDeposit("Refund for flight with ID " + flight.getId() + ": $" + std::to_string(flight.getCost()));
    reservation_handler.updateReservation(reservation);
    flight_handler.updateFlight(flight);
    payment_method_handler.updatePaymentMethod(payment_method);
    std::cout << "Refund Amount: $" << flight.getCost() << " has been credited to payment method with ID " << payment_method.getId() << "\n";
    std::cout << "Reservation " << reservation.getId() << " has been successfully cancelled.\n";
    state = BookingAgentMenuState::BOOKING_AGENT_MENU;
}
