#include "Entities/Flight.hpp"

Flight::Flight(std::string Origin, std::string Destination,
               std::string Departure_Date_and_Time, std::string Arrival_Date_and_Time,
               std::string Aircraft_id, double cost, int seatCount, std::string status)
    : Origin(std::move(Origin)), Destination(std::move(Destination)),
      Departure_Date_and_Time(std::move(Departure_Date_and_Time)),
      Arrival_Date_and_Time(std::move(Arrival_Date_and_Time)),
      Aircraft_id(std::move(Aircraft_id)), cost(cost), seatCount(seatCount), status(std::move(status))
{
    availableSeats = seatCount;
    seats.resize(seatCount, 'O');
    int reminder = seatCount % ROW;
    if (reminder != 0)
    {
        for (int i = 0; i < ROW - reminder; ++i)
        {
            seats.push_back('*');
        }
    }
}

const std::string &Flight::getId() const { return id; }
const std::string &Flight::getOrigin() const { return Origin; }
const std::string &Flight::getDestination() const { return Destination; }
const std::string &Flight::getDepartureDateAndTime() const { return Departure_Date_and_Time; }
const std::string &Flight::getArrivalDateAndTime() const { return Arrival_Date_and_Time; }
const std::string &Flight::getAircraftId() const { return Aircraft_id; }
const std::string &Flight::getBoardingGate() const { return BoardingGate; }
const std::vector<std::string> &Flight::getPassengers() const { return Passengers_id; }
const std::vector<std::string> &Flight::getPilots() const { return Pilots_id; }
const std::string &Flight::getBoardingTime() const { return BoardingTime; }
const std::vector<std::string> &Flight::getFlightAttendants() const { return FlightAttendants_id; }
const std::string &Flight::getStatus() const { return status; }
double Flight::getCost() const { return cost; }
const std::vector<char> &Flight::getSeats() const { return seats; }
int Flight::getSeatCount() const { return seatCount; }
int Flight::getAvailableSeats() const { return availableSeats; }

void Flight::setId(const std::string &id) { this->id = id; }
void Flight::setOrigin(const std::string &origin) { this->Origin = origin; }
void Flight::setDestination(const std::string &destination) { this->Destination = destination; }
void Flight::setDeparture_Date_and_Time(const std::string &Departure_Date_and_Time) { this->Departure_Date_and_Time = Departure_Date_and_Time; }
void Flight::setArrival_Date_and_Time(const std::string &Arrival_Date_and_Time) { this->Arrival_Date_and_Time = Arrival_Date_and_Time; }
void Flight::setAircraft_id(const std::string &Aircraft_id) { this->Aircraft_id = Aircraft_id; }
void Flight::setBoardingGate(const std::string &boardingGate) { this->BoardingGate = boardingGate; }
void Flight::setCost(double cost) { this->cost = cost; }
void Flight::setBoardingTime(const std::string &boardingTime) { this->BoardingTime = boardingTime; }
void Flight::setStatus(const std::string &status) { this->status = status; }

void Flight::addPassenger(const std::string &passengerId) { Passengers_id.push_back(passengerId); }
void Flight::removePassenger(const std::string &passengerId)
{
    auto it = std::find(Passengers_id.begin(), Passengers_id.end(), passengerId);
    if (it != Passengers_id.end())
    {
        Passengers_id.erase(it);
    }
}

void Flight::addPilot(const std::string &pilotId) { Pilots_id.push_back(pilotId); }
void Flight::removePilot(const std::string &pilotId)
{
    auto it = std::find(Pilots_id.begin(), Pilots_id.end(), pilotId);
    if (it != Pilots_id.end())
    {
        Pilots_id.erase(it);
    }
}

void Flight::addFlightAttendant(const std::string &flightAttendantId) { FlightAttendants_id.push_back(flightAttendantId); }
void Flight::removeFlightAttendant(const std::string &flightAttendantId)
{
    auto it = std::find(FlightAttendants_id.begin(), FlightAttendants_id.end(), flightAttendantId);
    if (it != FlightAttendants_id.end())
    {
        FlightAttendants_id.erase(it);
    }
}
int Flight::seat_to_index(std::string seat) const
{
    int row = static_cast<int>(seats.size() / ROW);
    int index = 0;
    int columnNumber;
    try
    {
        columnNumber = std::stoi(seat.substr(1)); // Convert the substring starting from index 1 to an integer
    }
    catch (const std::invalid_argument &)
    {
        std::cout << "Invalid seat format.\n";
        return -1; // Invalid numeric part
    }
    catch (const std::out_of_range &)
    {
        std::cout << "Seat number out of range.\n";
        return -1; // Out of range
    }

    switch (seat[0])
    {
    case 'A':
        index = row * 5;
        break;
    case 'B':
        index = row * 4;
        break;
    case 'C':
        index = row * 3;
        break;
    case 'D':
        index = row * 2;
        break;
    case 'E':
        index = row;
        break;
    case 'F':
        index = 0;
        break;
    default:
        std::cout << "Invalid seat number.\n";
        return -1; // Invalid seat number
    }
    index += columnNumber - 1;
    if (index < 0 || index >= seats.size())
    {
        std::cout << "Seat number out of range.\n";
        return -1;
    }
    return index;
}
bool Flight::bookSeat(std::string seat)
{

    int index = seat_to_index(seat);
    if (index == -1)
    {
        return false;
    }
    if (seats[index] == 'O')
    {
        seats[index] = '*';
        availableSeats--;
        std::cout << "Seat booked successfully.\n";
        return true;
    }
    else
    {
        std::cout << "Seat already booked.\n";
    }
    return false;
}

bool Flight::dropSeat(std::string seat)
{
    int index = seat_to_index(seat);
    if (index == -1)
    {
        std::cout << "Invalid seat number.\n";
        return false;
    }
    if (seats[index] == '*')
    {
        seats[index] = 'O';
        availableSeats++;
        std::cout << "Seat dropped successfully.\n";
        return true;
    }
    else
    {
        std::cout << "Seat is not booked.\n";
    }
    return false;
}

void Flight::displaySeats() const
{
    int column = static_cast<int>(seats.size() / ROW);
    int width = (column * 3) + 3 + 2;
    int length = 15;
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0 || i == 0 && j == width - 1 || i == length - 1 && j == 0 || i == length - 1 && j == width - 1)
            {
                std::cout << '+';
            }
            else if (j == 0 || j == width - 1)
            {
                std::cout << '|';
            }
            else if (i == 0 || i == length - 1 || i == 6 || i == 8)
            {
                std::cout << '-';
            }
            else if (j < 5)
            {
                switch (i)
                {
                case 1:
                    std::cout << "F | ";
                    j = 5;
                    break;
                case 3:
                    std::cout << "E | ";
                    j = 5;
                    break;
                case 5:
                    std::cout << "D | ";
                    j = 5;
                    break;
                case 7:
                    std::cout << "    ";
                    int k;
                    for (k = 1; k < column; k++)
                    {
                        if (k < 10)
                        {
                            std::cout << k << "  ";
                        }
                        else
                        {
                            std::cout << k << " ";
                        }
                    }
                    std::cout << k;
                    j = width - 2;
                    break;
                case 9:
                    std::cout << "C | ";
                    j = 5;
                    break;
                case 11:
                    std::cout << "B | ";
                    j = 5;
                    break;
                case 13:
                    std::cout << "A | ";
                    j = 5;
                    break;
                default:
                    std::cout << "  | ";
                    j = 5;
                    break;
                }
            }
            else if ((i == 2) || (i == 4) || (i == 10) || (i == 12))
            {
                std::cout << " ";
                if (j == width - 2)
                {
                    std::cout << " ";
                }
            }
            else
            {
                if (j == width - 2)
                {
                    std::cout << seats[index++] << " ";
                }
                else
                {
                    std::cout << seats[index++] << "  ";
                    j += 2;
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout << "O->Available    *->Unavailable" << std::endl;
}

void Flight::displayInfo() const
{
    std::cout << "Flight ID: " << id << "\n"
              << "Origin: " << Origin << "\n"
              << "Destination: " << Destination << "\n"
              << "Departure Date and Time: " << Departure_Date_and_Time << "\n"
              << "Arrival Date and Time: " << Arrival_Date_and_Time << "\n"
              << "Aircraft ID: " << Aircraft_id << "\n"
              << "Status: " << status << "\n"
              << "Available Seats: " << availableSeats << "\n"
              << "Cost: $" << cost << "\n"
              << "Passengers: ";
    for (const auto &passengerId : Passengers_id)
    {
        std::cout << passengerId << " ";
    }
    std::cout << "\n"
              << "Pilots: ";
    for (const auto &pilotId : Pilots_id)
    {
        std::cout << pilotId << " ";
    }
    std::cout << "\n"
              << "Flight Attendants: ";
    for (const auto &flightAttendantId : FlightAttendants_id)
    {
        std::cout << flightAttendantId << " ";
    }
    std::cout << "\n";
}
