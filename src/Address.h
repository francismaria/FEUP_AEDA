/*
 * Address.h
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include "Libraries.h"

class Address{
	std::string street;
	std::string zipCode;
	std::string city;
	std::string country;
public:
	Address(){}
	Address(std::string street, std::string zipCode, std::string city, std::string country);
	std::string getStreet() const;
	std::string getZipCode() const;
	std::string getCity() const;
	std::string getCountry() const;
	void setStreet(std::string s);
	void setZipCode(std::string z);
	void setCity(std::string c);
	void setCountry(std::string cnt);		//Não será melhor ter uma class Country que guarda todos os paises que a empresa de mudanças opera e a sua distancia??
	bool operator ==(const Address& a1);
	friend std::ostream& operator <<(std::ostream& o, const Address a){
		o << "Address: " << a.street << ", " << a.zipCode << "\n\t\t " << a.city << ", " << a.country;
		return o;
	}
};


class NonExistentAddress{
public:
	std::string street, zipCode, country;
	NonExistingAddress(std::string s, std::string z, std::string c, std::string cnt);
	std::string getStreet() const{ return street; }
	std::string getZipCode() const{ return zipCode; }
	std::string getCountry() const{ return country; }
};


#endif /* COUNTRY_H_ */
