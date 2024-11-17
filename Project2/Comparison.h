#ifndef COMPARISON_H
#define COMPARISON_H

#include "Product.h"
//6)
// Шаблонна функція для порівняння двох об'єктів за ціною
template <typename T>
T comparePrice(const T& obj1, const T& obj2) {
    if (obj1.getPrice() > obj2.getPrice()) {
        return obj1;
    }
    else if (obj1.getPrice() < obj2.getPrice()) {
        return obj2;
    }
    else {
        return T("Equal", 0, 0, 0, "", "", 0, false); // Якщо ціни однакові
    }
}


#endif


