/*
 * Country.h
 *
 *  Created on: 12/11/2017
 *      Author: Francisco
 */

#ifndef COUNTRY_H_
#define COUNTRY_H_

#include "Libraries.h"

class Country{
	std::string name;
	std::vector<Country*> zone1;
	std::vector<Country*> zone2;
public:
	Country(std::string n);
	std::string getName() const;
	void addZone1Country(Country* c);
	void addZone2Country(Country* c);
	std::vector<Country*> getZone1() const;
	std::vector<Country*> getZone2() const;
	friend std::ostream& operator <<(std::ostream& o, const Country* c){
		o << c->getName();
		return o;
	}
};




#endif /* COUNTRY_H_ */
