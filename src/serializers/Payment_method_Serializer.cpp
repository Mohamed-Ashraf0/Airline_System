#include "serializers/Payment_method_Serializer.hpp"

nlohmann::json paymentmethodJsonSerializer::serialize(const PaymentMethod &payment_method)
{
    nlohmann::json j({{"method", payment_method.method},
                      {"details", payment_method.details},
                      {"withdrawl", payment_method.withdrawl},
                      {"deposit", payment_method.deposit}});
    return j;
}

PaymentMethod paymentmethodJsonSerializer::deserialize(const nlohmann::json &j)
{
    PaymentMethod payment_method;
    j.at("id").get_to(payment_method.id);
    j.at("method").get_to(payment_method.method);
    j.at("details").get_to(payment_method.details);
    j.at("withdrawl").get_to(payment_method.withdrawl);
    j.at("deposit").get_to(payment_method.deposit);
    return payment_method;
}