#include "Handlers/input_Handler.hpp"

// Implementation of InputException
InputException::InputException(const std::string &msg) : message(msg) {}

const char *InputException::what() const noexcept
{
    return message.c_str();
}

// Implementation of InputHandler
InputHandler::InputHandler()
{
    std::cin.exceptions(std::ios::failbit | std::ios::badbit);
}

int InputHandler::getInteger(int n)
{
    int x;

    while (true)
    {
        try
        {
            std::cout << "Enter choice: ";
            std::cin >> x;

            // Validate the input range
            if (x < 1 || x > n)
            {
                throw InputException("Invalid input! Please choose a menu option between 1 and " + std::to_string(n) + ".");
            }

            break; 
        }
        catch (const std::ios_base::failure &e)
        {
            std::cerr << "Invalid input! Please enter a valid integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        catch (const InputException &e)
        {
            std::cerr << e.what() << "\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return x;
}