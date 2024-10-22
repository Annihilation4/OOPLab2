#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include "Product.h"

class Warehouse {
private:
    std::vector<Product> products; // Вектор продуктів на складі

public:
    // Метод для додавання продукту на склад
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // Метод для відображення всіх продуктів на складі
    void displayProducts() const {
        std::cout << "Products in Warehouse:" << std::endl;
        for (const auto& product : products) {
            std::cout << "- " << product.getName() << " (ID: " << product.getProductID() << ")" << std::endl;
        }
    }
};

#endif


