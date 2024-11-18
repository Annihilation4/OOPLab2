#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "Product.h"
#include "Client.h"

class Cart {
private:
    int cartID;
    Client client;
    float totalAmount;
    int itemCount; // Змінна для зберігання кількості товарів
    float discount;
    std::string status;
    std::string creationDate;
    std::vector<Product> products; // Вектор для зберігання продуктів у кошику

public:
    // Дефолтний конструктор
    Cart()
        : cartID(0), totalAmount(0.0), itemCount(0), discount(0.0), status("Active"), creationDate("") {}
    // Конструктор базового класу
    Cart(int cartID, const Client& client, float totalAmount = 0.0, float discount = 0.0, const std::string& status = "Active", const std::string& creationDate = "")
        : cartID(cartID), client(client), totalAmount(totalAmount), discount(discount), status(status), creationDate(creationDate) {}

    // Деструктор для очищення кошика
    ~Cart() {
        products.clear(); // Очищення продуктів
        std::cout << "Cart cleared." << std::endl;
    }

    // Геттери
    int getCartID() const { return cartID; }
    Client getClient() const { return client; }
    float getTotalAmount() const { return totalAmount; }
    int getItemCount() const { return itemCount; }
    float getDiscount() const { return discount; }
    std::string getStatus() const { return status; }
    std::string getCreationDate() const { return creationDate; }
    std::vector<Product> getProducts() const { return products; }

    // Сеттеры
    void setTotalAmount(float amount) { totalAmount = amount; }
    void setItemCount(int count) { itemCount = count; }
    void setDiscount(float discount) { this->discount = discount; }
    void setStatus(const std::string& status) { this->status = status; }
    void setCreationDate(const std::string& date) { creationDate = date; }

};

#endif





