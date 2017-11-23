/*
 * Payment.h
 *
 *  Created on: 17/11/2017
 *      Author: Francisco Maria / Jo�o Gama Amaral
 */

#ifndef PAYMENT_H_
#define PAYMENT_H_

#include "Libraries.h"
#include "Date.h"

const float TAX_ATM = 0;
const float TAX_CREDIT_CARD = 0.05;
const float TAX_BANK_TRANSFER = 0;
const float TAX_END_OF_MONTH = 0;

typedef enum status {PENDING, RECEIVED} PaymentStatus;

class Payment{
	float paymentTax;
	PaymentStatus status;
public:
	Payment();
	Payment(float value);
	float getPaymentTax() const;
	std::string getPaymentStatus() const;
	void validate();
	virtual std::string getPaymentType() const = 0;
};

class ATM: public Payment{
	std::string entity;
	int reference;
public:
	ATM(std::string e);
	std::string getEntity() const;
	int getReference() const;
	std::string getPaymentType() const;
};

class CreditCard: public Payment{ //Permitido apenas a clientes empresariais registados taxa de 5%
	std::string cardNumber;
	static float tax;
public:
	CreditCard();
	~CreditCard(){};
	CreditCard(std::string creditCardID);
	std::string getCardNumber() const;
	std::string getPaymentTax();
	static float getTax();
	std::string getPaymentType() const;

};

class BankTransfer: public Payment{
	std::string IBAN;
public:
	BankTransfer();
	BankTransfer(std::string iban);
	std::string getIBAN() const;
	std::string getPaymentType() const;
};

class EndOfMonth: public Payment{
	int endMonth;
public:
	EndOfMonth();
	EndOfMonth(int month);
	int getEndMonth() const;
	std::string getPaymentType() const;
};




#endif /* PAYMENT_H_ */
