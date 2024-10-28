#ifndef PAYMENT_METHOD_H
#define PAYMENT_METHOD_H

#include <iostream>

class PaymentMethod {
private:
    int methodID;
    std::string methodName;
    float transactionFee;
    bool isSecure;
    std::string currency;
    int maxLimit;
    std::string provider;
    float discountRate;

public:
    // Конструктор
    PaymentMethod()
        : methodID(0), transactionFee(0.0f), isSecure(false), maxLimit(0), discountRate(0.0f) {}

    // Конструктор з параметрами
    PaymentMethod(int methodID, const std::string& methodName, float transactionFee,
        bool isSecure, const std::string& currency, int maxLimit,
        const std::string& provider, float discountRate)
        : methodID(methodID), methodName(methodName), transactionFee(transactionFee),
        isSecure(isSecure), currency(currency), maxLimit(maxLimit),
        provider(provider), discountRate(discountRate) {}

    // Геттери
    int getMethodID() const { return methodID; }
    std::string getMethodName() const { return methodName; }
    float getTransactionFee() const { return transactionFee; }
    bool getIsSecure() const { return isSecure; }
    std::string getCurrency() const { return currency; }
    int getMaxLimit() const { return maxLimit; }
    std::string getProvider() const { return provider; }
    float getDiscountRate() const { return discountRate; }

    // Сеттери
    void setMethodID(int methodID) { this->methodID = methodID; }
    void setMethodName(const std::string& methodName) { this->methodName = methodName; }
    void setTransactionFee(float transactionFee) { this->transactionFee = transactionFee; }
    void setIsSecure(bool isSecure) { this->isSecure = isSecure; }
    void setCurrency(const std::string& currency) { this->currency = currency; }
    void setMaxLimit(int maxLimit) { this->maxLimit = maxLimit; }
    void setProvider(const std::string& provider) { this->provider = provider; }
    void setDiscountRate(float discountRate) { this->discountRate = discountRate; }
};

#endif


