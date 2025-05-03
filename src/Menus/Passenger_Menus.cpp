#include "Menus/Passenger_Menus.hpp"
PassengerMenu::PassengerMenu()
    : state(PassengerMenuState::LOGIN)
{
}
void PassengerMenu::displayMenu()
{
    while (state != PassengerMenuState::EXIT)
    {
        switch (state)
        {
        case PassengerMenuState::LOGIN:
            displayLogin();
            break;
        case PassengerMenuState::PASSENGER_MENU:
            displayPassengerMenu();
            break;
        case PassengerMenuState::BOOK_FLIGHT:
            displayBookFlight();
            break;
        case PassengerMenuState::VIEW_RESERVATIONS:
            displayViewReservations();
            break;
        case PassengerMenuState::CHECK_IN:
            displayCheckIn();
            break;
        case PassengerMenuState::MANAGE_PAYMENT_METHOD:
            displayManagePaymentMethodMenu();
            break;
        case PassengerMenuState::LOGOUT:
            displayLogout();
            break;
        }
    }
}
void PassengerMenu::displayLogin()
{
    std::string username, password;
    std::cin.ignore();
    std::cout << "--- Passenger Login ---\n";
    std::cout << "Username: ";
    getline(std::cin, username);
    std::cout << "Password: ";
    getline(std::cin, password);
    try
    {
        currentPassenger = std::make_unique<Passenger>(passenger_handler.login(username, password));
        std::cout << "Login successful! Welcome, " << currentPassenger->getName() << ".\n";
        state = PassengerMenuState::PASSENGER_MENU;
    }
    catch (const std::exception &e)
    {
        std::cout << "Login failed: " << e.what() << "\n";
        state = PassengerMenuState::EXIT;
    }
}
void PassengerMenu::displayPassengerMenu()
{
    std::cout << "--- Passenger Menu ---\n";
    std::cout << "1. Book a Flight\n";
    std::cout << "2. View My Reservations\n";
    std::cout << "3. Check-In\n";
    std::cout << "4. Manage Payment Method\n";
    std::cout << "5. Logout\n";

    int choice;
    choice = inputHandler.getInteger(5);

    switch (choice)
    {
    case 1:
        state = PassengerMenuState::BOOK_FLIGHT;
        break;
    case 2:
        state = PassengerMenuState::VIEW_RESERVATIONS;
        break;
    case 3:
        state = PassengerMenuState::CHECK_IN;
        break;
    case 4:
        state = PassengerMenuState::MANAGE_PAYMENT_METHOD;
        break;
    case 5:
        state = PassengerMenuState::LOGOUT;
        break;
    default:
        break;
    }
}
void PassengerMenu::displayManagePaymentMethodMenu()
{
    std::cout << "--- Manage Payment Method ---\n";
    std::cout << "1. Add Payment Method\n";
    std::cout << "2. Update Payment Method\n";
    std::cout << "3. View Payment Method\n";
    std::cout << "4. Remove Payment Method\n";
    std::cout << "5. Back to Passenger Menu\n";

    int choice;
    choice = inputHandler.getInteger(5);

    switch (choice)
    {
    case 1:
        addPaymentMethod();
        state = PassengerMenuState::MANAGE_PAYMENT_METHOD;
        break;
    case 2:
        updatePaymentMethod();
        state = PassengerMenuState::MANAGE_PAYMENT_METHOD;
        break;
    case 3:
        viewTransactions();
        state = PassengerMenuState::MANAGE_PAYMENT_METHOD;
        break;
    case 4:
        removePaymentMethod();
        state = PassengerMenuState::MANAGE_PAYMENT_METHOD;
        break;
    case 5:
        state = PassengerMenuState::PASSENGER_MENU;
        break;
    default:
        break;
    }
}
PaymentMethod PassengerMenu::addPaymentMethod()
{
    PaymentMethod payment_method;
    std::cout << "--- Add Payment Method ---\n";
    if (currentPassenger->getPaymentMethod() != "")
    {
        std::cout << "already have a payment method.\n";
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
    currentPassenger->setPaymentMethod(payment_method.getId());
    passenger_handler.updatePassenger(*currentPassenger);
    std::cout << "Payment method " << payment_method.getId() << " has been successfully added.\n";
    return payment_method;
}
void PassengerMenu::updatePaymentMethod()
{
    std::cout << "--- Update Payment Method ---\n";
    if (currentPassenger->getPaymentMethod() == "")
    {
        std::cout << "No payment method to update.\n";
        return;
    }
    std::string method, details;
    PaymentMethod payment_method;
    std::cout << "Enter New Payment Method: ";
    std::cin.ignore();
    getline(std::cin, method);
    std::cout << "Enter New Payment Details: ";
    getline(std::cin, details);
    payment_method.setMethod(method);
    payment_method.setDetails(details);
    payment_method.setId(currentPassenger->getPaymentMethod());
    payment_method_handler.updatePaymentMethod(payment_method);
    std::cout << "Payment method " << payment_method.getId() << " has been successfully updated.\n";
}
void PassengerMenu::viewTransactions()
{
    std::cout << "--- View Transactions ---\n";
    if (currentPassenger->getPaymentMethod() == "")
    {
        std::cout << "No payment method to view.\n";
        return;
    }
    try
    {
        payment_method_handler.viewPaymentMethod(currentPassenger->getPaymentMethod());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
    }
}
void PassengerMenu::removePaymentMethod()
{
    std::cout << "--- Remove Payment Method ---\n";
    if (currentPassenger->getPaymentMethod() == "")
    {
        std::cout << "No payment method to remove.\n";
        return;
    }
    std::string payment_method_id = currentPassenger->getPaymentMethod();
    payment_method_handler.removePaymentMethod(currentPassenger->getPaymentMethod());
    currentPassenger->setPaymentMethod("");
    passenger_handler.updatePassenger(*currentPassenger);
    std::cout << "Payment " << payment_method_id << " has been successfully removed.\n";
}
void PassengerMenu::displayBookFlight()
{
    std::cout << "--- Book Flight ---\n";
    Flight flight;
    try
    {
        flight = flight_handler.chooseFlight(REMOVE_ADD_OPTION, currentPassenger->getId());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        state = PassengerMenuState::PASSENGER_MENU;
        return;
    }
    PaymentMethod payment_method;
    if (currentPassenger->getPaymentMethod() == "")
    {
        std::cout << "No payment method available.\n";
        std::cin.ignore();
        std::cout << "1. Add new Payment Method\n";
        std::cout << "2. Back to Main Menu\n";
        int choice;
        choice = inputHandler.getInteger(2);
        switch (choice)
        {
        case 1:
            payment_method = addPaymentMethod();
            break;
        case 2:
            state = PassengerMenuState::PASSENGER_MENU;
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
            payment_method = payment_method_handler.getPaymentMethodById(currentPassenger->getPaymentMethod());
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what();
            state = PassengerMenuState::PASSENGER_MENU;
            return;
        }
    }
    flight.displaySeats();
    std::string seat;
    do
    {
        std::cout << "Enter seat number: " << std::flush;
        std::getline(std::cin, seat);
    } while (!flight.bookSeat(seat));
    flight.addPassenger(currentPassenger->getId());
    std::string withdrawalDescription = "Cost for flight with ID " + flight.getId() + ": $" + std::to_string(flight.getCost());
    payment_method.addWithdrawl(withdrawalDescription);
    Reservation reservation(flight.getId(), currentPassenger->getId(), payment_method.getId());
    reservation.setSeat(seat);
    reservation.setStatus("Booked");
    reservation_handler.addReservation(reservation);
    currentPassenger->addReservation(reservation.getId());
    flight_handler.updateFlight(flight);
    passenger_handler.updatePassenger(*currentPassenger);
    payment_method_handler.updatePaymentMethod(payment_method);
    std::cout << "Reservation " << reservation.getId() << " has been successfully created.\n";
    state = PassengerMenuState::PASSENGER_MENU;
}
void PassengerMenu::displayViewReservations()
{
    std::cout << "--- View My Reservations ---\n";

    if (currentPassenger->getReservations().empty())
    {
        std::cout << "No reservations found.\n";
        state = PassengerMenuState::PASSENGER_MENU;
        return;
    }
    for (const auto &reservationId : currentPassenger->getReservations())
    {
        try
        {
            Reservation reservation = reservation_handler.getReservation(reservationId);
            std::cout << "   Reservation ID: " << reservation.getId() << "\n";
            std::cout << "   Flight ID: " << reservation.getFlightId() << "\n";
            std::cout << "   Passenger ID: " << reservation.getPassengerId() << "\n";
            std::cout << "   Status: " << reservation.getStatus() << "\n";
            std::cout << "   Seat: " << reservation.getSeat() << "\n";
            std::cout << "   Payment Method ID: " << reservation.getPaymentMethodId() << "\n\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what();
        }
    }
    state = PassengerMenuState::PASSENGER_MENU;
}
void PassengerMenu::displayCheckIn()
{
    std::cout << "--- Check-In ---\n";
    std::vector<std::string> reservations = currentPassenger->getReservations();
    if (reservations.empty())
    {
        std::cout << "No reservations found.\n";
        state = PassengerMenuState::PASSENGER_MENU;
        return;
    }
    int index = 1;
    std::cout << "---Available Reservations---\n";
    for (const auto &reservationId : reservations)
    {
        std::cout << index << ". Reservation ID: " << reservationId << "\n";
    }
    index = inputHandler.getInteger(reservations.size());
    Reservation reservation = reservation_handler.getReservation(reservations[index - 1]);
    if (reservation.getStatus() == "CheckedIn")
    {
        std::cout << "Already checked in.\n";
        state = PassengerMenuState::PASSENGER_MENU;
        return;
    }

    Flight flight = flight_handler.getFlightById(reservation.getFlightId());

    reservation.setStatus("CheckedIn");
    reservation_handler.updateReservation(reservation);
    Boarding boarding(reservation.getPassengerId(), reservation.getFlightId(), reservation.getId());
    boarding_handler.addBoarding(boarding);
    currentPassenger->addBoardingPass(boarding.getId());
    passenger_handler.updatePassenger(*currentPassenger);
    std::cout << "Check-In Successful!\n";
    std::cout << "Boarding Pass : " << boarding.getId() << "\n";
    std::cout << "-----------------------------\n";
    std::cout << "Reservation ID: " << reservation.getId() << "\n";
    std::cout << "Passenger: " << currentPassenger->getName() << "\n";
    std::cout << "Flight ID: " << reservation.getFlightId() << "\n";
    std::cout << "Origin: " << flight.getOrigin() << "\n";
    std::cout << "Destination: " << flight.getDestination() << "\n";
    std::cout << "Departure: " << flight.getDepartureDateAndTime() << "\n";
    std::cout << "seat: " << reservation.getSeat() << "\n";
    std::cout << "Boarding Gate: " << flight.getBoardingGate() << "\n";
    std::cout << "Boarding Time: " << flight.getBoardingTime() << "\n";
    std::cout << "-----------------------------\n";
    state = PassengerMenuState::PASSENGER_MENU;
}
void PassengerMenu::displayLogout()
{
    std::cout << "Logging out. Goodbye!\n";
    state = PassengerMenuState::EXIT;
}