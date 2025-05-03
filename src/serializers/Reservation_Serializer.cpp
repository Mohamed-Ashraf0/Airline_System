#include "serializers/Reservation_Serializer.hpp"

nlohmann::json reservationJsonSerializer::serialize(const Reservation &reservation)
{
    nlohmann::json j({{"flightId", reservation.flightId},
                      {"passengerId", reservation.passengerId},
                      {"status", reservation.status},
                      {"paymentMethodId", reservation.paymentMethodId},
                      {"seat", reservation.seat}});
    return j;
}

Reservation reservationJsonSerializer::deserialize(const nlohmann::json &j)
{
    Reservation reservation;
    j.at("id").get_to(reservation.id);
    j.at("flightId").get_to(reservation.flightId);
    j.at("passengerId").get_to(reservation.passengerId);
    j.at("status").get_to(reservation.status);
    j.at("paymentMethodId").get_to(reservation.paymentMethodId);
    j.at("seat").get_to(reservation.seat);
    return reservation;
}