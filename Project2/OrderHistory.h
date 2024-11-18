#ifndef ORDER_HISTORY_H
#define ORDER_HISTORY_H

#include <iostream>
#include <vector>
#include "Client.h"
#include "Order.h"
#include "Product.h"

class OrderHistory : public Client {
private:
    std::vector<Order> previousOrders; // Зберігає попередні замовлення

public:
    // Конструктор
    OrderHistory(const std::string& name, int clientID, const std::string& email,
        const std::string& phone, const std::string& address,
        const PaymentMethod& paymentMethod, const std::string& membershipType, float totalSpent)
        : Client(name, clientID, email, phone, address, paymentMethod, membershipType, totalSpent) {}

    // 2)
    OrderHistory(const std::string& lastName, const std::string& email, int number) : Client(lastName, email, number) {}
};

#endif 


