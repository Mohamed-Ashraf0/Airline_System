#ifndef MENU_HPP
#define MENU_HPP

class Menu {
public:
    virtual void displayMenu() = 0; 
    virtual ~Menu() = default;  
};
#endif 