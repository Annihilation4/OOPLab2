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

};

#endif

