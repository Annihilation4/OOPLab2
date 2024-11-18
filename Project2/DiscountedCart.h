#ifndef DISCOUNTED_CART_H
#define DISCOUNTED_CART_H

#include "Cart.h"
#include <string>
#include <ctime>

// 3) ���������� �������� ����, ���� ��������� �������� ����� ����������� �� ���������� �ᒺ��� ��������������

class DiscountedCart : private Cart {
private:
    float discountPercentage;
    std::string discountCode;
    std::time_t expiryDate;
    bool isValidDiscount;

public:
    // ����������� � �����������
    DiscountedCart(int cartID, const Client& client, float discountPercentage, const std::string& discountCode, std::time_t expiryDate, float totalAmount = 0.0, float discount = 0.0, const std::string& status = "Active", const std::string& creationDate = "")
        : Cart(cartID, client, totalAmount, discount, status, creationDate), // ������ ������������ �������� �����
        discountPercentage(discountPercentage), discountCode(discountCode), expiryDate(expiryDate), isValidDiscount(true) {}
    ~DiscountedCart() {}

};

#endif



