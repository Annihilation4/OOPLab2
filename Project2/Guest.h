#ifndef GUEST_H
#define GUEST_H
#include "Person.h"
#include <iostream>
#include <fstream>

class Guest : virtual public Person { // Віртуальне наслідування
public:
    // Дефолтний конструктор
    Guest() : Person() {
        // Додаткові ініціалізації, якщо потрібно
    }
    // Конструктор класу Guest, який викликає конструктор класу Person
    Guest(const std::string& name) : Person(name, email) {
        // Додаткові ініціалізації, якщо потрібно
    }

    void displayInfo() const override {
        std::cout << "Guest Info\n";
        std::cout << "Name: " << name << "\n"; // Виведення імені гостя
    }

    // Інші властивості та методи для гостей
};

#endif

