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

    // Метод для отримання загальної вартості
    float getTotalCost() const {
        float total = 0.0;
        for (const auto& product : products) {
            total += product.getPrice() * product.getQuantity(); // Передбачається, що є getPrice() та getQuantity() для товарів
        }
        return total;
    }

    // Метод для отримання кількості товарів у кошику
    int getItemCountInCart() const {
        return products.size(); // Повертає кількість продуктів у векторі
    }

    // Метод для додавання продукту до кошика
    void addProduct(const Product& product) {
        products.push_back(product); // Додає продукт до вектора
    }

    // Метод для відображення продуктів у кошику
    void displayProducts() const {
        std::cout << "Products in Cart:" << std::endl;
        for (const auto& product : products) {
            std::cout << "- " << product.getName() << " (Quantity: " << product.getQuantity() << ", Price: " << product.getPrice() << ")" << std::endl;
        }
    }
    //3)
    // Оператор [] для доступу до елемента за індексом
    Product& operator[](size_t index) {
        if (index >= products.size()) throw std::out_of_range("Invalid index");
        return products[index];
    }

    // Оператор += для додавання товару
    Cart& operator+=(const Product& product) {
        products.push_back(product);
        return *this;
    }

    // Оператор -= для видалення товару за індексом
    Cart& operator-=(size_t index) {
        if (index >= products.size()) throw std::out_of_range("Invalid index");
        products.erase(products.begin() + index);
        return *this;
    }

    // Оператор *= для масового знижування цін
    Cart& operator*=(double discount) {
        for (auto& product : products) {
            product.setPrice(product.getPrice() * discount);
        }
        return *this;
    }

    // Оператор = для копіювання кошика
    Cart& operator=(const Cart& other) {
        if (this != &other) {
            cartID = other.cartID;
            client = other.client;
            totalAmount = other.totalAmount;
            itemCount = other.itemCount;
            discount = other.discount;
            status = other.status;
            creationDate = other.creationDate;
            products = other.products;
        }
        return *this;
    }
    // Оператор * для обчислення загальної вартості кошика
    float operator*(const Cart& cart) {
        float totalCost = 0.0;
        for (const auto& product : cart.products) {
            totalCost += product.getPrice() * product.getQuantity(); // Ціна * Кількість
        }
        return totalCost;
    }

};

#endif





