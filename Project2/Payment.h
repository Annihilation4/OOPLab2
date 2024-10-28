#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <vector>
#include "Order.h"
#include "PaymentMethod.h"
class Payment
{
private:
	int paymentID;
	float amount;
	PaymentMethod paymentMethod;
	Order order;
	std::string paymentDate;
	std::string status;
	std::string transactionID;
	bool isRefundable;

public:
	Payment(int paymentID, float amount, const PaymentMethod& paymentMethod, const Order& order, const std::string& paymentDate,
		const std::string& status, const std::string& transactionID, bool isRefundable) : paymentID(paymentID), amount(amount),
		paymentMethod(paymentMethod), order(order), paymentDate(paymentDate), status(status), transactionID(transactionID),
		isRefundable(isRefundable) {}
	~Payment() {}
};
#endif
