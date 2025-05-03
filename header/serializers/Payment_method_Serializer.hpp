#ifndef PAYMENT_METHOD_SERIALIZER_HPP
#define PAYMENT_METHOD_SERIALIZER_HPP

#include "nlohmann/json.hpp"
#include "Entities/Payment_method.hpp"

class paymentmethodJsonSerializer
{
public:
    static nlohmann::json serialize(const PaymentMethod &payment_method);
    static PaymentMethod deserialize(const nlohmann::json &j);
};

#endif 