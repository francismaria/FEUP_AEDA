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

class ConnectionCountryInfo{
	Country* country;
	int zone;
	float baseRate;
public:
	ConnectionCountryInfo(){};
	ConnectionCountryInfo(Country* c, int z, float bR);
	std::string getName() const;
	int getZone() const;
	float getBaseRate() const;
};


#endif /* CONNECTIONCOUNTRYINFO_H_ */
