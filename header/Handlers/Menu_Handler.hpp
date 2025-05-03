#ifndef MENU_HANDLER_HPP
#define MENU_HANDLER_HPP

#include "Menus/Menu.hpp"
#include "Menus/Passenger_Menus.hpp"
#include "Menus/Admin_Menus.hpp"
#include "Menus/Booking_agent_Menus.hpp"
#include "Handlers/input_Handler.hpp"

#include <memory>
#include <iostream>

class MenuHandler
{
private:
  InputHandler inputHandler; 
public:
    std::unique_ptr<Menu> getMenu();
};

#endif