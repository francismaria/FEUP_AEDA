/*
 * Country.cpp
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Country.h"

Country::Country(std::string n): name(n){}

std::string Country::getName() const{ return name; }

void Country::addZone1Country(Country* c){ zone1.push_back(c); }

void Country::addZone2Country(Country* c){ zone2.push_back(c); }

std::vector<Country*> Country::getZone1() const{ return zone1; }

std::vector<Country*> Country::getZone2() const{ return zone2; }

void Country::printZoneCountries() const{

	unsigned int i, j;

	std::cout << "\t\t\t\t\t    ZONE 1:\n" << std::endl;

	for(i = 0; i < zone1.size(); i++){
		std::cout << "\t\t\t\t\t\t\t" << i+1 << " - " << zone1[i] << std::endl;
	}

	std::cout << "\n\t\t\t\t\t    ZONE 2:\n" << std::endl;

	for(j = 0; j < zone2.size(); j++){
		std::cout << "\t\t\t\t\t\t\t" << j+i+1 << " - " << zone2[j] << std::endl;
	}
}

Country* Country::getDestination(int id, int& zoneOne){

	if(id <= (zone1.size()-1)){
		zoneOne = 1;
		std::cout << "\n\t\t\t\t\t  Estimated Delivery (ZONE 1): 7 - 10 working days." << std::endl;
		return zone1[id];
	}
	else{
		zoneOne = 2;
		std::cout << "\n\t\t\t\t\t  Estimated Delivery (ZONE 2): 15 - 22 working days." << std::endl;
		return zone2[id-zone1.size()];
	}
}



