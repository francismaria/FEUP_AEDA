/*
 * ConnectionCountryInfo.h
 *
 *  Created on: 13/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef CONNECTIONCOUNTRYINFO_H_
#define CONNECTIONCOUNTRYINFO_H_

#include "Libraries.h"

class Country;

/**
 * @brief Class that stores country information
 */
class ConnectionCountryInfo{
	Country* country;
	int zone;
	float baseRate;
public:
	/**
	 * Default constructor
	 */
	ConnectionCountryInfo(){};

	/**
	 *  Constructor to initialize a new country with its info
	 */
	ConnectionCountryInfo(Country* c, int z, float bR);

	/**
	 * @return 1 or 2 depending on its zone
	 */
	int getZone() const;

	/**
	 * @return base rate of its country
	 */
	float getBaseRate() const;

	/**
	 * @brief gets country name
	 * @return string with country name
	 */
	std::string getName() const;

	/**
	 * @brief gets country
	 * @return country pointer
	 */
	Country* getCountry() const;
};


#endif /* CONNECTIONCOUNTRYINFO_H_ */
