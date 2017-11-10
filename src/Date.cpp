/*
 * Date.cpp
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Date.h"

Date::Date(int d, int m, int y): day(d), month(m), year(y){}

int Date::getDay() const{ return day; }

int Date::getMonth() const{ return month; }

int Date::getYear() const{ return year; }

void Date::setDay(int d){ day = d; }

void Date::setMonth(int m){ month = m; }

void Date::setYear(int y){ year = y; }
/*
b ool Date::operator <(const Date& d1){
	if(year < d1.getYear())
			return true;
	else if(year > d1.getYear())
		return false;

	if(month < d1.getMonth())
		return true;
	else if(month > d1.getMonth())
		return false;

	if(day < d1.getDay())
		return true;
	return false;
}*/

bool Date::operator ==(const Date& d1){
	if(day == d1.getDay() && month == d1.getMonth() && year == d1.getYear())
		return true;
	return false;

}



