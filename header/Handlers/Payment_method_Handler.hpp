#ifndef PAYMENT_METHOD_HANDLER_HPP
#define PAYMENT_METHOD_HANDLER_HPP

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "nlohmann/json.hpp"
#include "Entities/Payment_method.hpp"
#include "Handlers/File_Handler.hpp"
#include "serializers/Payment_method_Serializer.hpp"

class paymentmethodhandler
{
private:
    std::unique_ptr<FileHandler> fileHandler;

public:
    paymentmethodhandler();
    void addPaymentMethod(PaymentMethod &payment_method);
    void updatePaymentMethod(PaymentMethod &payment_method);
    void removePaymentMethod(const std::string &payment_methodId);
    void viewPaymentMethod(const std::string &payment_methodId);
    PaymentMethod getPaymentMethodById(const std::string &payment_methodId);
};

#endif