/*
 * Shipping.cpp
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / Jo�o Gama Amaral
 */

#include "Shipping.h"

/*Shipping::Shipping(std::string street, std::string zipCode, std::string city, std::string country) :
	origin(Address(street, zipCode, city, country)){}*/

Shipping::Shipping(Address& o, Address& d, int zone/*, Date& b, Date& e*/): origin(o), destination(d){

	if(zone == 1){
		//VARIAR OS PRE�OS DE SHIPPING COM O PA�S
		cost = 50;
	}
	else{
		cost = 50 + 0.1*50;
	}
}

float Shipping::getCost() const{ return cost; }

const Address& Shipping::getOrigin() const { return this->origin; }



