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
    std::vector<Product> products; // Вектор продуктів на складі

public:
};

#endif


