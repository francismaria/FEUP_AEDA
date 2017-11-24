/*
 * Country.h
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef COUNTRY_H_
#define COUNTRY_H_

#include "Libraries.h"
#include"ConnectionCountryInfo.h"

/**
 * @brief Class that stores all country information
 */
class Country{
	std::string name;
	std::vector<ConnectionCountryInfo> countriesInfo;
public:
	/**
	 * Country Constructor
	 */
	Country(std::string n);

	/**
	 * @return string with name of country
	 */
	std::string getName() const;

	/**
	 * @brief add country to countriesInfo
	 * @param ci ConnectionCountryInfo to add to countriesInfo
	 */
	void addCountryConnection(ConnectionCountryInfo& ci);

	/**
	 * @return all countries
	 */
	std::vector<ConnectionCountryInfo> getCountriesInfo() const;

	/**
	 * @brief gets the destination country
	 * @param id destination country ID
	 * @return ConnectionCountryInfo object (destination country)
	 */
	ConnectionCountryInfo& getDestination(int id);

	/**
	 * @brief prints all countries to which it operates to
	 */
	void printCountriesTo() const;

	/**
	 * @brief prints a country
	 * @param o ostream
	 * @param c country
	 * @return ostream
	 */
	friend std::ostream& operator <<(std::ostream& o, const Country* c){
		o << c->getName();
		return o;
	}
};

#endif /* COUNTRY_H_ */
