/*
 * Shipping.h
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef SHIPPING_H_
#define SHIPPING_H_

#include "Libraries.h"
#include "Address.h"
#include "Date.h"

class Shipping{
	Address origin;
	Address destination;
	Date beggining;
	Date end;
	float cost;
public:
	Shipping(){};
	Shipping(Address& o, Address& d, int zone/*, Date& b, Date& e*/);
	void setOrigin(std::string street, std::string zipCode, std::string city, std::string country);
	void setDestination(std::string street, std::string zipCode, std::string city, std::string country);
	void setBeggining();
	void setEnd();
	float getCost() const;
	const Address& getOrigin() const;
	const Address& getDestination() const;
	const Date& getBeggining() const;
	const Date& getEnd() const;
};



#endif /* SHIPPING_H_ */
