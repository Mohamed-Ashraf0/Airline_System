#include "Entities/Payment_method.hpp"
#include <iostream>

// Constructor
PaymentMethod::PaymentMethod( const std::string &method, const std::string &details)
    : method(method), details(details) {}

// Getters
const std::string &PaymentMethod::getId() const {
    return id;
}

const std::string &PaymentMethod::getMethod() const {
    return method;
}

const std::string &PaymentMethod::getDetails() const {
    return details;
}

// Setters
void PaymentMethod::setId(const std::string &id) {
    this->id = id;
}

void PaymentMethod::setMethod(const std::string &method) {
    this->method = method;
}

void PaymentMethod::setDetails(const std::string &details) {
    this->details = details;
}
void PaymentMethod::addDeposit(const std::string &amount) {
    deposit.push_back(amount);
}
void PaymentMethod::addWithdrawl(const std::string &amount) {
    withdrawl.push_back(amount);
}
const std::vector<std::string> &PaymentMethod::getWithdrawl() const {
    return withdrawl;
}
const std::vector<std::string> &PaymentMethod::getDeposit() const {
    return deposit;
}
// Display Information
void PaymentMethod::displayInfo() const {
    std::cout << "Payment Method ID: " << id << "\n"
              << "Method: " << method << "\n"
              << "Details: " << details << "\n";
              
    std::cout << "Deposits: ";
    for (const auto &amount : deposit) {
        std::cout << amount << " ";
    }
    std::cout << "\nWithdrawals: ";
    for (const auto &amount : withdrawl) {
        std::cout << amount << " ";
    }
    std::cout << "\n";
}