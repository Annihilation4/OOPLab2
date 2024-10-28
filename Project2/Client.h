#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Product.h"
#include "Order.h"
#include "PaymentMethod.h"

class Client {
private:
    std::string name;
    int clientID;
    std::string email;
    std::string phone;
    std::string address;
    PaymentMethod paymentMethod;
    std::string membershipType;
    float totalSpent;

protected:
    //2)
    std::string lastName;

public:
    //2)
    int number;
    // Конструктор 
    Client() : clientID(0), totalSpent(0.0f) {}

    // Конструктор с параметрами
    Client(const std::string& name, int clientID, const std::string& email, const std::string& phone,
        const std::string& address, const PaymentMethod& paymentMethod, const std::string& membershipType, float totalSpent)
        : name(name), clientID(clientID), email(email), phone(phone), address(address),
        paymentMethod(paymentMethod), membershipType(membershipType), totalSpent(totalSpent) {}

    Client(const std::string& lastName, const std::string& email, int number) : lastName(lastName), email(email), number(number) {}

    // Деструктор
    ~Client() {
        std::cout << "Client destructor called for Client ID: " << clientID << std::endl;
    }

    // Геттеры
    std::string getName() const { return name; }
    int getClientID() const { return clientID; }
    std::string getEmail() const { return email; }
    std::string getPhone() const { return phone; }
    std::string getAddress() const { return address; }
    PaymentMethod getPaymentMethod() const { return paymentMethod; }
    std::string getMembershipType() const { return membershipType; }
    float getTotalSpent() const { return totalSpent; }
    std::string getLastName() const { return lastName; }
    int getNumber() const { return number; }

    // Сеттеры
    void setName(const std::string& name) { this->name = name; }
    void setClientID(int clientID) { this->clientID = clientID; }
    void setEmail(const std::string& email) { this->email = email; }
    void setPhone(const std::string& phone) { this->phone = phone; }
    void setAddress(const std::string& address) { this->address = address; }
    void setPaymentMethod(const PaymentMethod& paymentMethod) { this->paymentMethod = paymentMethod; }
    void setMembershipType(const std::string& membershipType) { this->membershipType = membershipType; }
    void setTotalSpent(float totalSpent) { this->totalSpent = totalSpent; }

    // Публічний метод
    void displayInfo() const {
        std::cout << "Name: " << name << ", Client ID: " << clientID << ", Email: " << email << std::endl;
    }
};

#endif


