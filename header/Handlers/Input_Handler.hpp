#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>
#include <limits>

class InputException : public std::exception
{
private:
    std::string message;

public:
    explicit InputException(const std::string &msg);
    const char *what() const noexcept override;
};

class InputHandler
{
public:
    InputHandler();
    int getInteger(int n=0);
};

#endif 