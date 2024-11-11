#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include "Person.h"

class Administrator : public Person {  // ³������� ����
private:
    std::string password;
    int accessLevel;
    float salary;
    float timeOnline;
    int numberOfProcessedOrders;
    int rating;

public:
    // ����������� �� �������������
    Administrator()
        : Person("Default Name", "default@example.com"),  // ������� ����������� �������� ����� Person
        password("defaultPassword"), accessLevel(1), salary(0.0f), timeOnline(0.0f),
        numberOfProcessedOrders(0), rating(0) {}
    // ����������� �� �������������
    Administrator(const std::string& name, const std::string& email, const std::string& password,
        int accessLevel, float salary, float timeOnline, int numberOfProcessedOrders, int rating)
        : Person(name, email), password(password), accessLevel(accessLevel), salary(salary),
        timeOnline(timeOnline), numberOfProcessedOrders(numberOfProcessedOrders), rating(rating) {}

    // ��������� ��������� �������
    void displayInfo() const override {
        std::cout << "Administrator Info:\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Email: " << email << "\n";
        std::cout << "Password: " << password << "\n";
        std::cout << "Access Level: " << accessLevel << "\n";
        std::cout << "Salary: " << salary << "\n";
        std::cout << "Time Online: " << timeOnline << "\n";
        std::cout << "Processed Orders: " << numberOfProcessedOrders << "\n";
        std::cout << "Rating: " << rating << "\n";
    }

    virtual ~Administrator() {  // ³��������� ����������
        std::cout << "Administrator Destructor Called" << std::endl;
    }
};

#endif





