#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    std::string email;

public:
    Person() : name(""), email("") {}
    Person(const std::string& name, const std::string& email) : name(name), email(email) {}

    // Віртуальна функція для виведення інформації
    virtual void displayInfo() const = 0;  // Чисто віртуальна функція, що має бути реалізована в похідних класах

    virtual ~Person() {}  // Віртуальний деструктор
};

#endif

