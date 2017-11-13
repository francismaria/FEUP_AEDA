/*
 * Shipping.cpp
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Shipping.h"

/*Shipping::Shipping(std::string street, std::string zipCode, std::string city, std::string country) :
	origin(Address(street, zipCode, city, country)){}*/

Shipping::Shipping(Address& o, Address& d/*, Date& b, Date& e*/): origin(o), destination(d)/*, beggining(b), end(e)*/{}

const Address& Shipping::getOrigin() const { return this->origin; }



