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

class Country{
	std::string name;
	std::vector<Country*> zone1;
	std::vector<Country*> zone2;
	std::vector<ConnectionCountryInfo> countriesInfo;
public:
	Country(std::string n);
	std::string getName() const;
	void addZone1Country(Country* c);
	void addZone2Country(Country* c);
	std::vector<Country*> getZone1() const;
	std::vector<Country*> getZone2() const;
	void addCountryConnection(ConnectionCountryInfo& ci);
	std::vector<ConnectionCountryInfo> getCountriesInfo() const;
	ConnectionCountryInfo& getDestination(int id);
	//void printZoneCountries() const;
	void printCountriesTo() const;
	friend std::ostream& operator <<(std::ostream& o, const Country* c){
		o << c->getName();
		return o;
	}
};
/*
class ConnectionCountryInfo{
	Country* country;
	int zone;
	float baseRate;
public:
	ConnectionCountryInfo(){};
	ConnectionCountryInfo(Country* c, int z, float bR);
	int getZone() const;
	float getBaseRate() const;
};*/




#endif /* COUNTRY_H_ */
