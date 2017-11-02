/*
 * Address.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */


#include "Address.h"

Address::Address(std::string street, std::string zipCode, std::string city, std::string country){
	this->street = street;
	this->zipCode = zipCode;
	this->city = city;
	this->country = country;
}

std::string Address::getStreet() const{ return street; }

std::string Address::getZipCode() const{ return zipCode; }

std::string Address::getCity() const{ return city; }

std::string Address::getCountry() const{ return country; }

void Address::setStreet(std::string s){ street = s; }

void Address::setZipCode(std::string z){ zipCode = z; }

void Address::setCity(std::string c){ city = c; }

void Address::setCountry(std::string cnt){ country = cnt; }

bool Address::operator ==(const Address& a1){
	if(this->street == a1.getStreet() && this->city == a1.getCity()
			&& this->zipCode == a1.getZipCode() && this->country == a1.getCountry())
		return true;
	return false;
}




