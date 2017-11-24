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
	std::vector<ConnectionCountryInfo> countriesInfo;
public:
	Country(std::string n);
	std::string getName() const;
	void addCountryConnection(ConnectionCountryInfo& ci);
	std::vector<ConnectionCountryInfo> getCountriesInfo() const;
	ConnectionCountryInfo& getDestination(int id);		//getDestinationCountry ---> RENAME!!
	void printCountriesTo() const;
	friend std::ostream& operator <<(std::ostream& o, const Country* c){
		o << c->getName();
		return o;
	}
};

#endif /* COUNTRY_H_ */
