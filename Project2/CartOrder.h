#ifndef CART_ORDER_H
#define CART_ORDER_H

#include "Cart.h"
#include "Order.h"

class CartOrder : public Cart, public Order {
public:
    // Конструктор
    CartOrder(const Cart& cart, const Order& order)
        : Cart(cart), Order(order) {}
    ~CartOrder() {}

    // Метод для відображення інформації про замовлення з кошика
    void displayCartOrderInfo() const {
        std::cout << "Cart Order Information:" << std::endl;
        std::cout << "Order ID: " << getOrderID() << std::endl;
        std::cout << "Items in Cart: " << getItemCount() << std::endl; // Get item count from Cart
        std::cout << "Total Price: " << getTotalPrice() << std::endl;
    }
};

#endif

