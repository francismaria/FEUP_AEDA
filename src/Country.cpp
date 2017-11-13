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




