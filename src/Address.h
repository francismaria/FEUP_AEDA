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

/**
 * 	@brief Class that stores all information about an address.
 */
class Address{
	std::string street;
	std::string zipCode;
	std::string city;
	std::string country_aux;
	ConnectionCountryInfo country;
public:
	/**
	 * Default Constructor
	 */
	Address(){}

	/**
	 * Constructor with country as string
	 */
	Address(std::string street, std::string zipCode, std::string city, std::string country);

	/**
	 * Constructor with country as pointer
	 */
	Address(std::string street, std::string zipCode, std::string city, Country* c);

	/**
	 * Constructor with country as ConnectionCountryInfo object
	 */
	Address(std::string street, std::string zipCode, std::string city, ConnectionCountryInfo& c);

	/**
	 * @return string with street address
	 */
	std::string getStreet() const;

	/**
	 * @return string with zip code
	 */
	std::string getZipCode() const;

	/**
	 * @return string with city
	 */
	std::string getCity() const;

	std::string getCountryAux() const;

	/**
	 * @return country as ConnectionCountryInfo object
	 */
	ConnectionCountryInfo& getCountry();

	/**
	 * @brief sets street address
	 * @param s
	 */
	void setStreet(std::string s);

	/**
	 * @brief sets zip code
	 * @param z
	 */
	void setZipCode(std::string z);

	/**
	 * @brief sets city name
	 * @param c
	 */
	void setCity(std::string c);

	/**
	 * @brief sets country
	 * @param cnt
	 */
	void setCountry(std::string cnt);

	/**
	 * @brief compares two addresses
	 * @param a1
	 * @return true or false if addresses are equal
	 */
	bool operator ==(const Address& a1);

	/**
	 * @brief prints address in determined way
	 * @param o ostream
	 * @param a an address
	 * @return ostream
	 */
	friend std::ostream& operator <<(std::ostream& o, const Address a){
		o << "Address: " << a.street << ", " << a.zipCode << "\n\t\t " << a.city << ", " << a.country_aux;
		return o;
	}
};

#endif /* COUNTRY_H_ */
