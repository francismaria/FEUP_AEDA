/*
 * Exceptions.h
 *
 *  Created on: 14/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include "Libraries.h"

class NonExistingClient{
public:
	int ID;
	std::string name;
	NonExistingClient(int id){ ID = id; }
	NonExistingClient(std::string n){ name = n; }
	int getID() const{ return ID; }
	std::string getName(){ return name; }
};

class NonExistingCompany{
public:
	std::string name;
	NonExistingCompany(std::string n){ name = n; }
	std::string getName(){ return name; }
};

class NonExistingParticular{
public:
	std::string name;
	NonExistingParticular(std::string n){ name = n; }
	std::string getName(){ return name; }
};

class NonExistingDate{
public:
	int day, month, year;
	NonExistingDate(int d, int m, int y){ day = d; month = m; year = y; }
	int getDay() const{ return day; }
	int getMonth() const{ return month; }
	int getYear() const{ return year; }
};





#endif /* EXCEPTIONS_H_ */
