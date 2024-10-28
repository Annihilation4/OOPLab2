#ifndef SALE_H
#define SALE_H

#include <iostream>
#include <vector>
#include "Order.h"
#include "PaymentMethod.h"
class Sale
{
private:
	int saleID;
	Order order;
	float discount;
	float finalAmount;
	PaymentMethod paymentMethod;
	std::string saleDate;
	std::string sellerName;
	std::string status;
public:
	Sale(int saleID, const Order& order, float discount, float finalAmount, const PaymentMethod& paymentMethod,
		const std::string saleDate, const std::string sellerName, const std::string status) : saleID(saleID), 
		order(order), discount(discount), finalAmount(finalAmount), paymentMethod(paymentMethod), saleDate(saleDate),
		sellerName(sellerName), status(status){}
	~Sale() {}
};
#endif

