#include "Entities/Flight.hpp"

Flight::Flight(std::string Origin, std::string Destination,
               std::string Departure_Date_and_Time, std::string Arrival_Date_and_Time,
               std::string Aircraft_id, double cost, int seatCount)
    : Origin(std::move(Origin)), Destination(std::move(Destination)),
      Departure_Date_and_Time(std::move(Departure_Date_and_Time)),
      Arrival_Date_and_Time(std::move(Arrival_Date_and_Time)),
      Aircraft_id(std::move(Aircraft_id)), cost(cost), seatCount(seatCount)
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

const std::string &Flight::getId() const
{
    return id;
}

const std::string &Flight::getOrigin() const
{
    return Origin;
}

const std::string &Flight::getDestination() const
{
    return Destination;
}

const std::string &Flight::getDepartureDateAndTime() const
{
    return Departure_Date_and_Time;
}

const std::string &Flight::getArrivalDateAndTime() const
{
    return Arrival_Date_and_Time;
}

const std::string &Flight::getAircraftId() const
{
    return Aircraft_id;
}

double Flight::getCost() const
{
    return cost;
}

const std::vector<std::string> &Flight::getPassengers() const
{
    return Passengers_id;
}

// Setters
void Flight::setId(const std::string &id)
{
    this->id = id;
}

void Flight::setOrigin(const std::string &origin)
{
    this->Origin = origin;
}

void Flight::setDestination(const std::string &destination)
{
    this->Destination = destination;
}

void Flight::setDeparture_Date_and_Time(const std::string &Departure_Date_and_Time)
{
    this->Departure_Date_and_Time = Departure_Date_and_Time;
}

void Flight::setArrival_Date_and_Time(const std::string &Arrival_Date_and_Time)
{
    this->Arrival_Date_and_Time = Arrival_Date_and_Time;
}

void Flight::setAircraft_id(const std::string &Aircraft_id)
{
    this->Aircraft_id = Aircraft_id;
}

void Flight::setCost(double cost)
{
    this->cost = cost;
}

// Passenger Management
void Flight::addPassenger(const std::string &passengerId)
{
    Passengers_id.push_back(passengerId);
}

void Flight::removePassenger(const std::string &passengerId)
{
    auto it = std::find(Passengers_id.begin(), Passengers_id.end(), passengerId);
    if (it != Passengers_id.end())
    {
        Passengers_id.erase(it);
    }
}
void Flight::setStatus(FlightStatus status)
{
    this->status = status;
}
FlightStatus Flight::getStatus() const
{
    return status;
}
void Flight::bookSeat(int index)
{
    if (index >= 0 && index < seats.size())
    {
        if (seats[index] == 'O')
        {
            seats[index] = '*';
            availableSeats--;
        }
        else
        {
            std::cout << "Seat already booked.\n";
        }
    }
    else
    {
        std::cout << "Invalid seat index.\n";
    }
}
void Flight::dropSeat(int index)
{
    if (index >= 0 && index < seats.size())
    {
        if (seats[index] == '*')
        {
            seats[index] = 'O';
            availableSeats++;
        }
        else
        {
            std::cout << "Seat is not booked.\n";
        }
    }
    else
    {
        std::cout << "Invalid seat index.\n";
    }
}
void Flight::setBoardingGate(const std::string &boardingGate)
{
    this->BoardingGate = boardingGate;
}
const std::string &Flight::getBoardingGate() const
{
    return BoardingGate;
}
void Flight::displaySeats() const
{
    int column = seats.size() / ROW;
    int width = (column * 3) + 3 + 2;
    int length = 15;
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0 || i == 0 && j == width - 1 || i == length - 1 && j == 0 || i == length - 1 && j == width - 1)
            {
                cout << '+';
            }
            else if (j == 0 || j == width - 1)
            {
                cout << '|';
            }
            else if (i == 0 || i == length - 1 || i == 6 || i == 8)
            {
                cout << '-';
            }
            else if (j < 5)
            {
                switch (i)
                {
                case 1:
                    cout << "F | ";
                    j = 5;
                    break;
                case 3:
                    cout << "E | ";
                    j = 5;
                    break;
                case 5:
                    cout << "D | ";
                    j = 5;
                    break;
                case 7:
                    cout << "    ";
                    int k;
                    for (k = 1; k < column; k++)
                    {
                        if (k < 10)
                        {
                            cout << k << "  ";
                        }
                        else
                        {
                            cout << k << " ";
                        }
                    }
                    cout << k;
                    j = width - 2;
                    break;
                case 9:
                    cout << "C | ";
                    j = 5;
                    break;
                case 11:
                    cout << "B | ";
                    j = 5;
                    break;
                case 13:
                    cout << "A | ";
                    j = 5;
                    break;
                default:
                    cout << "  | ";
                    j = 5;
                    break;
                }
            }
            else if (i == 2 || i == 4 | i == 10 || i == 12)
            {
                cout << " ";
                if (j == width - 2)
                {
                    cout << " ";
                }
            }
            else
            {
                if (j == width - 2)
                {
                    cout << x[index++] << " ";
                }
                else
                {
                    cout << x[index++] << "  ";
                    j += 2;
                }
            }
        }
        cout << endl;
    }
    cout << "O->Available    *->Unavailable" << endl;
}
void Flight::displayInfo() const
{
    std::cout << "Flight ID: " << id << "\n"
              << "Origin: " << Origin << "\n"
              << "Destination: " << Destination << "\n"
              << "Departure Date and Time: " << Departure_Date_and_Time << "\n"
              << "Arrival Date and Time: " << Arrival_Date_and_Time << "\n"
              << "Aircraft ID: " << Aircraft_id << "\n"
              << "Status: " << (status == FlightStatus::SCHEDULED ? "Scheduled" : (status == FlightStatus::DELAYED ? "Delayed" : "Cancelled")) << "\n"
              << "Available Seats: " << availableSeats << "\n"
              << "Cost: $" << cost << "\n"
              << "Passengers: ";
    for (const auto &passengerId : Passengers_id)
    {
        std::cout << passengerId << " ";
    }
    std::cout << "\n";
}