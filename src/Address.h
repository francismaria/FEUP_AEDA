/*
 * Address.h
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include "Libraries.h"
#include "Country.h"

class Address{
	std::string street;
	std::string zipCode;
	std::string city;
	std::string country_aux;
	ConnectionCountryInfo country;
public:
	Address(){}
	Address(std::string street, std::string zipCode, std::string city, std::string country);
	Address(std::string street, std::string zipCode, std::string city, Country* c);
	Address(std::string street, std::string zipCode, std::string city, ConnectionCountryInfo& c);
	std::string getStreet() const;
	std::string getZipCode() const;
	std::string getCity() const;
	std::string getCountryAux() const;
	ConnectionCountryInfo& getCountry();
	void setStreet(std::string s);
	void setZipCode(std::string z);
	void setCity(std::string c);
	void setCountry(std::string cnt);
	bool operator ==(const Address& a1);
	friend std::ostream& operator <<(std::ostream& o, const Address a){
		o << "Address: " << a.street << ", " << a.zipCode << "\n\t\t " << a.city << ", " << a.country_aux;
		return o;
	}
};

#endif /* COUNTRY_H_ */
