#ifndef CLIENT_ORDER_H
#define CLIENT_ORDER_H

#include "Client.h"
#include "Order.h"
#include "PaymentMethod.h"

// 4) �������� �����������
class ClientOrder : public Client, public Order, public PaymentMethod {
public:
    // 8) ����������� �� �������������
    ClientOrder() : Client(), Order(), PaymentMethod() {}

    // 8) ����������� � �����������
    ClientOrder(const std::string& clientName, int clientID, const std::string& email, const std::string& phone,
        const std::string& address, const PaymentMethod& paymentMethod, const std::string& membershipType,
        float totalSpent, int orderID, const Product& product, int quantity,
        const PaymentMethod& orderPaymentMethod, bool isPaid, const std::string& deliveryAddress,
        const std::string& orderStatus)
        : Client(clientName, clientID, email, phone, address, paymentMethod, membershipType, totalSpent),
        Order(orderID, product, quantity, orderPaymentMethod, isPaid, deliveryAddress, orderStatus) {}

    // 7) ���������� ���������� �����������
    ~ClientOrder() {
        // ����� ������� ��� ��� ��������� �������, ���� �� ���������
        std::cout << "ClientOrder destructor called." << std::endl;
    }

    // ������ ��� ��������� ���������� ��� �볺��� �� ����������
    void displayClientOrderInfo() const {
        std::cout << "Client Name: " << getName() << "\n"
            << "Client ID: " << getClientID() << "\n"
            << "Order ID: " << getOrderID() << "\n"
            << "Product: " << getProduct().getName() << "\n"
            << "Quantity: " << getQuantity() << "\n"
            << "Total Price: " << getTotalPrice() << "\n"
            << "Payment Method: " << Order::getPaymentMethod().getMethodName() << "\n"
            << "Delivery Address: " << getDeliveryAddress() << "\n"
            << "Order Status: " << getOrderStatus() << std::endl;
    }
};
#endif

