#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Product.h"
#include "Order.h"

class Client {
private:
    std::string name;

public:
    Client(std::string n) : name(n) {}

    // Метод для отримання інформації про клієнта
    std::string getName() const {
        return name;
    }
};

#endif
