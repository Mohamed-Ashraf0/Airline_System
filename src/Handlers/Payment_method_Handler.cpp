#include "Handlers/Payment_method_Handler.hpp"

paymentmethodhandler::paymentmethodhandler()
    : fileHandler(FileHandler::create("../../Airline-Data/Payment_method.json")) {}

void paymentmethodhandler::addPaymentMethod(PaymentMethod &payment_method)
{
    nlohmann::json j = paymentmethodJsonSerializer::serialize(payment_method);
    std::string idPrefix = "PM";
    std::string id = fileHandler->writeJsonToFile(j, idPrefix);
    payment_method.setId(id);
}
void paymentmethodhandler::updatePaymentMethod(PaymentMethod &payment_method)
{
    nlohmann::json j = paymentmethodJsonSerializer::serialize(payment_method);
    fileHandler->updateJsonFile(j, payment_method.getId());
}
void paymentmethodhandler::removePaymentMethod(const std::string &payment_methodId)
{
    fileHandler->deleteEntityById(payment_methodId);
}
void paymentmethodhandler::viewPaymentMethod(const std::string &payment_methodId)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("Payment method not found.\n");
    }    
    if (j.find(payment_methodId) == j.end())
    {
        throw std::runtime_error("Payment method not found.\n");
    }
    j[payment_methodId]["id"] = payment_methodId;
    PaymentMethod payment_method = paymentmethodJsonSerializer::deserialize(j[payment_methodId]);
    payment_method.setId(payment_methodId);
    std::vector<std::string> withdrawls = payment_method.getWithdrawl();
    std::vector<std::string> deposits = payment_method.getDeposit();
    std::cout << "   Payment Method ID: " << payment_method.getId() << "\n";
    std::cout << "   Payment Method: " << payment_method.getMethod() << "\n";
    std::cout << "   Payment Details: " << payment_method.getDetails() << "\n";
    std::cout << "   Withdrawls:-\n";
    int index = 1;
    for (const auto& withdrawl : withdrawls) {
        std::cout << index++ << "   ."<< withdrawl << "\n";
    }
    std::cout << "\n";
    std::cout << "   Deposits:-\n";
    index = 1;
    for (const auto& deposit : deposits) {
        std::cout << index++ << "   ."<< deposit << "\n";
    }
    std::cout << "\n";
}
PaymentMethod paymentmethodhandler::getPaymentMethodById(const std::string &payment_methodId)
{
    nlohmann::json j;
    try
    {
        j = fileHandler->readJsonFromFile();
    }
    catch (const std::runtime_error &)
    {
        throw std::runtime_error("Payment method not found.\n");
    }  
    if (j.find(payment_methodId) == j.end())
    {
        throw std::runtime_error("Payment method not found.\n");
    }
    j[payment_methodId]["id"] = payment_methodId;
    PaymentMethod payment_method = paymentmethodJsonSerializer::deserialize(j[payment_methodId]);
    payment_method.setId(payment_methodId);
    return payment_method;
}