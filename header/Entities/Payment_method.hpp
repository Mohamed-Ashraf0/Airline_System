#ifndef PAYMENT_METHOD_HPP
#define PAYMENT_METHOD_HPP

#include <iostream>
#include <string>
#include "Entities/Entity.hpp"

class PaymentMethod: public Entity {
private:
    std::string method;   
    std::string details; 

public:

    PaymentMethod() = default;
    PaymentMethod(const std::string &method, const std::string &details);

    const std::string &getId() const;
    const std::string &getMethod() const;
    const std::string &getDetails() const;

    void setId(const std::string &id);
    void setMethod(const std::string &method);
    void setDetails(const std::string &details);

    void displayInfo() const;
};

#endif 