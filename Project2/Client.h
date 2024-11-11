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

class Client : virtual public Person { // Віртуальне наслідування
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

    // Публічний метод
    void displayInfo() const {
        std::cout << "Name: " << name << ", Client ID: " << clientID << ", Email: " << email << std::endl;
    }

    // Метод для створення динамічного клієнта
    static Client* createDynamicClient(int id, const std::string& name, const std::string& email) {
        if (clientCount >= MAX_CLIENTS) {
            throw std::overflow_error("Cannot create more clients, max limit reached");
        }
        try {
            Client* newClient = new Client(name, id, email, "Unknown", "Unknown", PaymentMethod(), "Unknown", 0.0f);

            clientCount++;  // Збільшуємо лічильник при створенні клієнта
            return newClient;
        }
        catch (const std::bad_alloc& e) {
            throw std::runtime_error("Memory allocation failed for new client");
        }
    }

    // Метод для відображення кількості створених клієнтів
    static int getClientCount() {
        return clientCount;
    }
    //6)
    // Метод видалення статичного об'єкта за критерієм (наприклад, ID клієнта)
    static void Service_Static(int clientID) {
        auto it = std::find_if(staticClients.begin(), staticClients.end(),
            [clientID](const Client& client) { return client.getClientID() == clientID; });

        if (it != staticClients.end()) {
            staticClients.erase(it);
            clientCount--;  // Зменшуємо лічильник клієнтів
        }
        else {
            throw std::runtime_error("Client with given ID not found in static array");
        }
    }

    // Метод видалення динамічного об'єкта за критерієм (наприклад, ID клієнта)
    static void Service_Dinamic(int clientID) {
        auto it = std::find_if(dynamicClients.begin(), dynamicClients.end(),
            [clientID](Client* client) { return client->getClientID() == clientID; });

        if (it != dynamicClients.end()) {
            delete* it;  // Видаляємо об'єкт, на який вказує вказівник
            dynamicClients.erase(it);
            clientCount--;  // Зменшуємо лічильник клієнтів
        }
        else {
            throw std::runtime_error("Client with given ID not found in dynamic array");
        }
    }

    // Метод для демонстрації виключних ситуацій
    static void testExceptions() {
        try {
            if (clientCount > MAX_CLIENTS) {
                throw std::overflow_error("Maximum clients reached. Cannot add more clients.");
            }

            // Приклад помилки пам'яті
            Client* client = new Client();
            delete client;

            throw std::bad_alloc();  // Імітація помилки виділення пам'яті

        }
        catch (const std::overflow_error& e) {
            std::cerr << "Overflow error: " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Runtime error: " << e.what() << std::endl;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory allocation error: " << e.what() << std::endl;
        }
    }

    void Client::Write(const std::string& filename) const {
        try {
            std::ofstream outFile(filename, std::ios::binary | std::ios::out);
            if (!outFile) {
                throw std::ios_base::failure("Failed to open file for writing.");
            }

            outFile.write(reinterpret_cast<const char*>(&clientID), sizeof(clientID));
            if (!outFile) {
                throw std::ios_base::failure("Failed to write client ID to file.");
            }

            outFile.write(name.c_str(), name.size() + 1);
            outFile.write(email.c_str(), email.size() + 1);
            outFile.write(phone.c_str(), phone.size() + 1);
            outFile.close();
            if (!outFile) {
                throw std::ios_base::failure("Failed to close file after writing.");
            }
        }
        catch (const std::ios_base::failure& e) {
            std::cerr << "File I/O error: " << e.what() << std::endl;
            throw;
        }
    }

    void Client::Read(const std::string& filename) {
        try {
            std::ifstream inFile(filename, std::ios::binary | std::ios::in);
            if (!inFile) {
                throw std::ios_base::failure("Failed to open file for reading.");
            }

            inFile.read(reinterpret_cast<char*>(&clientID), sizeof(clientID));
            if (inFile.eof()) throw std::runtime_error("Unexpected end of file reached.");
            if (!inFile) throw std::ios_base::failure("Failed to read client ID from file.");

            std::getline(inFile, name, '\0');
            std::getline(inFile, email, '\0');
            std::getline(inFile, phone, '\0');
            inFile.close();
            if (!inFile) {
                throw std::ios_base::failure("Failed to close file after reading.");
            }
        }
        catch (const std::ios_base::failure& e) {
            std::cerr << "File I/O error: " << e.what() << std::endl;
            throw;
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Runtime error: " << e.what() << std::endl;
            throw;
        }
    }
    void Service(Client& client, const std::string& filename);
};

#endif



