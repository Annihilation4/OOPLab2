#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Product.h"
#include "PaymentMethod.h"

class Order {
private:
    int orderID; // ID замовлення
    Product product; //продукт
    int quantity; //кількість
    double totalPrice; //загальна вартість
    PaymentMethod paymentMethod; //метод оплати
    bool isPaid; //статус оплати
    std::string deliveryAddress; //адреса доставки
    std::string orderStatus; //статус замовлення
    static int orderCount; // Статичне поле для підрахунку кількості замовлень

public:

    // конструктор без параметрів
    Order()
        : orderID(0), product(), quantity(0), totalPrice(0.0),
        paymentMethod(), isPaid(false), deliveryAddress(""), orderStatus("") {}

    // конструктор з параметрами
    Order(int id, const Product& p, int q, PaymentMethod pm, bool paid, std::string address, std::string status)
        : orderID(id), product(p), quantity(q),
        totalPrice(p.getPrice()* q), paymentMethod(pm),
        isPaid(paid), deliveryAddress(address), orderStatus(status) {}

    // конструктор копіювання
    Order(const Order& other)
        : orderID(other.orderID), product(other.product),
        quantity(other.quantity), totalPrice(other.totalPrice),
        paymentMethod(other.paymentMethod), isPaid(other.isPaid),
        deliveryAddress(other.deliveryAddress), orderStatus(other.orderStatus) {}

    ~Order() {
        std::cout << "Order destroyed: ID " << orderID << std::endl;
    }

    //гет, сет
    void setOrderID(int id) { orderID = id; }
    int getOrderID() const { return orderID; }

    void setProduct(Product p) { product = p; }
    Product getProduct() const { return product; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() const { return quantity; }

    void setTotalPrice(double tp) { totalPrice = tp; }
    double getTotalPrice() const { return totalPrice; }

    void setPaymentMethod(PaymentMethod pm) { paymentMethod = pm; }
    PaymentMethod getPaymentMethod() const { return paymentMethod; }

    void setIsPaid(bool paid) { isPaid = paid; }
    bool getIsPaid() const { return isPaid; }

    void setDeliveryAddress(std::string address) { deliveryAddress = address; }
    std::string getDeliveryAddress() const { return deliveryAddress; }

    void setOrderStatus(std::string status) { orderStatus = status; }
    std::string getOrderStatus() const { return orderStatus; }

};
#endif

