/*
 * Payment.h
 *
 *  Created on: 17/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef PAYMENT_H_
#define PAYMENT_H_

#include "Libraries.h"

const float TAX_ATM = 0;
const float TAX_CREDIT_CARD = 0.05;
const float TAX_BANK_TRANSFER = 0;

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
/*
class EndMonth: public Payment{ //Para clientes empresariais registados
	Date beggining;
	Date end;
public:
	EndMonth(){}
	//bool specialPayment(){return true;}
};*/




#endif /* PAYMENT_H_ */
