#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "Product.h"

class Cart {
private:
    std::vector<Product> products; // Вектор для зберігання продуктів у кошику

public:
    // Додавання продукту в кошик
    void addProduct(const Product& product) {
        products.push_back(product);
        std::cout << "Product added to cart: " << product.getName() << std::endl;
    }

    // Показати зміст кошика
    void showCartContents() const {
        std::cout << "Cart contents:" << std::endl;
        for (const auto& product : products) {
            std::cout << "- " << product.getName() << " (Price: " << product.getPrice() << ")" << std::endl;
        }
    }

    // Очистити кошик
    ~Cart() {
        products.clear(); // Очищення продуктів
        std::cout << "Cart cleared." << std::endl;
    }
};

#endif


