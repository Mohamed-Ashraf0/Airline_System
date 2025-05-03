#ifndef PAYMENT_METHOD_HPP
#define PAYMENT_METHOD_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Entities/Entity.hpp"

class PaymentMethod: public Entity {
private:
    std::string method;   
    std::string details; 
    std::vector<std::string> withdrawl;
    std::vector<std::string> deposit;
public:

    PaymentMethod() = default;
    PaymentMethod(const std::string &method, const std::string &details);

    const std::string &getId() const;
    const std::string &getMethod() const;
    const std::string &getDetails() const;
    const std::vector<std::string> &getWithdrawl() const;
    const std::vector<std::string> &getDeposit() const;

    void setId(const std::string &id);
    void setMethod(const std::string &method);
    void setDetails(const std::string &details);
    void displayInfo() const;
    void addDeposit(const std::string &amount);
    void addWithdrawl(const std::string &amount);
    friend class paymentmethodJsonSerializer;
};

#endif 