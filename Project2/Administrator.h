#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <vector>
#include <string> // Додано для використання std::string

class Administrator {
private:
    std::string name;
    std::string email;
    std::string password;
    int accessLevel;
    float salary;
    float timeOnline;
    int numberOfProcessedOrders;
    int rating;

public:
    // Конструктор за замовчуванням
    Administrator() : accessLevel(0), salary(0.0f), timeOnline(0.0f), numberOfProcessedOrders(0), rating(0) {}

    // Конструктор з параметрами
    Administrator(const std::string& name, const std::string& email, const std::string& password,
        int accessLevel, float salary, float timeOnline, int numberOfProcessedOrders, int rating)
        : name(name), email(email), password(password), accessLevel(accessLevel),
        salary(salary), timeOnline(timeOnline), numberOfProcessedOrders(numberOfProcessedOrders), rating(rating) {}

    ~Administrator() {}

    // Геттери
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getPassword() const { return password; }
    int getAccessLevel() const { return accessLevel; }
    float getSalary() const { return salary; }
    float getTimeOnline() const { return timeOnline; }
    int getNumberOfProcessedOrders() const { return numberOfProcessedOrders; }
    int getRating() const { return rating; }

    // Сеттеры
    void setName(const std::string& name) { this->name = name; }
    void setEmail(const std::string& email) { this->email = email; }
    void setPassword(const std::string& password) { this->password = password; }
    void setAccessLevel(int accessLevel) { this->accessLevel = accessLevel; }
    void setSalary(float salary) { this->salary = salary; }
    void setTimeOnline(float timeOnline) { this->timeOnline = timeOnline; }
    void setNumberOfProcessedOrders(int numberOfProcessedOrders) { this->numberOfProcessedOrders = numberOfProcessedOrders; }
    void setRating(int rating) { this->rating = rating; }
};

#endif


