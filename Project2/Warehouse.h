#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include "Product.h"

class Warehouse {
private:
    std::vector<Product> products; // ������ �������� �� �����

public:
    // ����� ��� ��������� �������� �� �����
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // ����� ��� ����������� ��� �������� �� �����
    void displayProducts() const {
        std::cout << "Products in Warehouse:" << std::endl;
        for (const auto& product : products) {
            std::cout << "- " << product.getName() << " (ID: " << product.getProductID() << ")" << std::endl;
        }
    }
};

#endif


