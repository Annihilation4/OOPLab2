#ifndef DISCOUNTED_CART_H
#define DISCOUNTED_CART_H

#include "Cart.h"
#include <string>
#include <ctime>

// 3) Додатковий похідний клас, який демонструє закритий спосіб наслідування із створенням об’єктів конструкторами

class DiscountedCart : private Cart {
private:
    float discountPercentage;
    std::string discountCode;
    std::time_t expiryDate;
    bool isValidDiscount;

public:
    // Конструктор з параметрами
    DiscountedCart(int cartID, const Client& client, float discountPercentage, const std::string& discountCode, std::time_t expiryDate, float totalAmount = 0.0, float discount = 0.0, const std::string& status = "Active", const std::string& creationDate = "")
        : Cart(cartID, client, totalAmount, discount, status, creationDate), // Виклик конструктора базового класу
        discountPercentage(discountPercentage), discountCode(discountCode), expiryDate(expiryDate), isValidDiscount(true) {}
    ~DiscountedCart() {}

    void applyDiscount() {
        if (validateDiscount()) {
            float totalCost = getTotalCost();
            float discountedCost = totalCost - (totalCost * (discountPercentage / 100));
            std::cout << "Total after discount: " << discountedCost << std::endl;
        }
        else {
            std::cout << "Discount expired or invalid.\n";
        }
    }

    bool validateDiscount() {
        std::time_t now = std::time(nullptr);
        isValidDiscount = (now <= expiryDate);
        return isValidDiscount;
    }
};

#endif



