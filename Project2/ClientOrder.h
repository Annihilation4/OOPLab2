#ifndef CLIENT_ORDER_H
#define CLIENT_ORDER_H

#include "Client.h"
#include "Order.h"
#include "PaymentMethod.h"

// 4) Множинне наслідування
class ClientOrder : public Client, public Order, public PaymentMethod {
public:
    // 8) Конструктор за замовчуванням
    ClientOrder() : Client(), Order(), PaymentMethod() {}

    // 8) Конструктор з параметрами
    ClientOrder(const std::string& clientName, int clientID, const std::string& email, const std::string& phone,
        const std::string& address, const PaymentMethod& paymentMethod, const std::string& membershipType,
        float totalSpent, int orderID, const Product& product, int quantity,
        const PaymentMethod& orderPaymentMethod, bool isPaid, const std::string& deliveryAddress,
        const std::string& orderStatus)
        : Client(clientName, clientID, email, phone, address, paymentMethod, membershipType, totalSpent),
        Order(orderID, product, quantity, orderPaymentMethod, isPaid, deliveryAddress, orderStatus) {}

};
#endif

