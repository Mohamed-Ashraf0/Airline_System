#include "serializers/Payment_method_Serializer.hpp"

nlohmann::json paymentmethodJsonSerializer::serialize(const PaymentMethod &payment_method)
{
    nlohmann::json j({{"method", payment_method.method},
                      {"details", payment_method.details}});
    return j;
}

PaymentMethod paymentmethodJsonSerializer::deserialize(const nlohmann::json &j)
{
    PaymentMethod payment_method;
    j.at("id").get_to(payment_method.id);
    j.at("method").get_to(payment_method.method);
    j.at("details").get_to(payment_method.details);
    return payment_method;
}