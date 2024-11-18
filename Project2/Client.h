#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Product.h"
#include "Order.h"
#include "PaymentMethod.h"
#include "Person.h"

class Client { // Віртуальне наслідування
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
    std::string lastName;

public:
    static std::vector<Client> staticClients;  // Статичний масив клієнтів
    static std::vector<Client*> dynamicClients;  // Динамічний масив клієнтів
    static const int MAX_CLIENTS = 5; // Максимальна кількість клієнтів
    static int clientCount; // Лічильник клієнтів
    int number;

    // Конструктор за замовчуванням
    Client() : name("Unknown"), clientID(0), email("Unknown"), phone("Unknown"), address("Unknown"),
        paymentMethod(PaymentMethod()), membershipType("Unknown"), totalSpent(0.0f), lastName("Unknown"), number(0) {}

    // Конструктор з параметрами
    Client(const std::string& name, int clientID, const std::string& email, const std::string& phone,
        const std::string& address, const PaymentMethod& paymentMethod, const std::string& membershipType, float totalSpent)
        : name(name), clientID(clientID), email(email), phone(phone), address(address),
        paymentMethod(paymentMethod), membershipType(membershipType), totalSpent(totalSpent), lastName("Unknown"), number(0) {}

    Client(const std::string& lastName, const std::string& email, int number) : lastName(lastName), email(email), number(number) {}

    virtual ~Client() {  // Віртуальний деструктор
        std::cout << "Client Destructor Called" << std::endl;
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

};

#endif



