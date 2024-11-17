#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include "Product.h"

class Warehouse {
private:
    int warehouseID;
    std::string location;
    std::string managerName;
    int capacity;
    int currentStock;
    int incomingStock;
    int outgoingStock;
    std::vector<Product> products; // ������ �������� �� �����

public:
    // ������ ����� � �����
    void addProduct(const Product& product) {
        products.push_back(product);
    }
    //4)
    // �������� ������� ��� ������ ����������/������������� ��������
    template <typename T>
    T findExtrema(bool findMax = true) const {
        if (products.empty()) {
            throw std::runtime_error("Warehouse is empty.");
        }

        T extrema = findMax ? products[0].getPrice() : products[0].getPrice();
        for (const auto& product : products) {
            if (findMax) {
                if (product.getPrice() > extrema) {
                    extrema = product.getPrice();
                }
            }
            else {
                if (product.getPrice() < extrema) {
                    extrema = product.getPrice();
                }
            }
        }
        return extrema;
    }

    // ��������� ������ ��������
    void displayProducts() const {
        for (const auto& product : products) {
            std::cout << product.getName() << " - Price: " << product.getPrice() << std::endl;
        }
    }
};

#endif


