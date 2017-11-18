/*
 * Payment.cpp
 *
 *  Created on: 17/11/2017
 *      Author: Francisco Maria / Jo�o Gama Amaral
 */

#include "Payment.h"


/****************************************/
/*				PAYMENT					*/
/****************************************/

Payment::Payment(){}

Payment::Payment(float value): paymentTax(value), status(PENDING){}

std::string Payment::getPaymentStatus() const{

	switch(status){
		case PENDING:
			return "PENDING";
		case RECEIVED:
			return "RECEIVED";
	}
}
float Payment::getPaymentTax() const{
	return paymentTax;
}


/****************************************/
/************     ATM	 ****************/
/****************************************/

ATM::ATM(std::string e): Payment(TAX_ATM), entity(e){
	reference = 14523;
}

std::string ATM::getEntity() const{
	return entity;
}

int ATM::getReference() const{
	return reference;
}

std::string ATM::getPaymentType() const{
	return "ATM";
}


/****************************************/
/**********   CREDIT CARD	************/
/****************************************/

float CreditCard::tax = 0.05; 		// 5% tax because of payment with cc

CreditCard::CreditCard(){}

CreditCard::CreditCard(std::string creditCardID): Payment(TAX_CREDIT_CARD), cardNumber(creditCardID){}

std::string CreditCard::getCardNumber() const{
	return cardNumber;
}

float CreditCard::getTax(){
	return tax;
}

std::string CreditCard::getPaymentType() const{
	return "Credit Card";
}

/****************************************/
/**********	  BANK TRANSFER  ************/
/****************************************/

BankTransfer::BankTransfer(){};

BankTransfer::BankTransfer(std::string iban): Payment(TAX_BANK_TRANSFER), IBAN(iban){}

std::string BankTransfer::getIBAN() const{
	return IBAN;
}

std::string BankTransfer::getPaymentType() const{
	return "Bank Transfer";
}


