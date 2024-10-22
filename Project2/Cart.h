#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include "Product.h"

class Cart {
private:
    std::vector<Product> products; // ������ ��� ��������� �������� � ������

public:
    // ��������� �������� � �����
    void addProduct(const Product& product) {
        products.push_back(product);
        std::cout << "Product added to cart: " << product.getName() << std::endl;
    }

    // �������� ���� ������
    void showCartContents() const {
        std::cout << "Cart contents:" << std::endl;
        for (const auto& product : products) {
            std::cout << "- " << product.getName() << " (Price: " << product.getPrice() << ")" << std::endl;
        }
    }

    // �������� �����
    ~Cart() {
        products.clear(); // �������� ��������
        std::cout << "Cart cleared." << std::endl;
    }
};

#endif


