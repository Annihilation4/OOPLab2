#ifndef ORDER_HISTORY_H
#define ORDER_HISTORY_H

#include <iostream>
#include <vector>
#include "Client.h"
#include "Order.h"
#include "Product.h"

class OrderHistory : public Client {
private:
    std::vector<Order> previousOrders; // ������ �������� ����������

public:
    // �����������
    OrderHistory(const std::string& name, int clientID, const std::string& email,
        const std::string& phone, const std::string& address,
        const PaymentMethod& paymentMethod, const std::string& membershipType, float totalSpent)
        : Client(name, clientID, email, phone, address, paymentMethod, membershipType, totalSpent) {}

    // 2)
    OrderHistory(const std::string& lastName, const std::string& email, int number) : Client(lastName, email, number) {}

    // ���� ���������� �� �����
    void addOrder(const Order& order) {
        previousOrders.push_back(order);
    }

    // ³������� ������ ���������
    void displayOrderHistory() const {
        std::cout << "Order History for Client: " << getName() << std::endl;
        if (previousOrders.empty()) {
            std::cout << "No previous orders." << std::endl;
            return;
        }

        for (const auto& order : previousOrders) {
            std::cout << "Order ID: " << order.getOrderID()
                << ", Product: " << order.getProduct().getName()
                << ", Quantity: " << order.getQuantity()
                << ", Total Price: $" << (order.getQuantity() * order.getProduct().getPrice())
                << std::endl;
        }
    }

    // 2) ���������� ����� ��� ������������ ������� � ��������� ���� � ��������
    void showClientDetails() {
        // ������ �� protected
        std::cout << "Last Name: " << getLastName() << std::endl;

        // ������ �� private
        std::cout << "Email: " << getEmail() << std::endl;

        // ������ �� public
        std::cout << "Number: " << getNumber() << std::endl;
    }
    // 6) using
    using Client::displayInfo;
};

#endif 


