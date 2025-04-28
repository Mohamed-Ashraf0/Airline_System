#include "Handlers/Menu_Handler.hpp"
#include<iostream>
int main() {
    MenuHandler menuHandler;
    while(1)
    {
        std::unique_ptr<Menu> menu = menuHandler.getMenu();
        menu->displayMenu(); 
    }
}