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

int Date::getHour() const{ return hour; }

int Date::getMinute() const{ return minute; }

void Date::setDay(int d){ day = d; }

void Date::setMonth(int m){ month = m; }

void Date::setYear(int y){ year = y; }

void Date::setHour(int h){ hour = h; }

void Date::setMinute(int m){ minute = m; }

NonExistingDate::NonExistingDate(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}

int NonExistingDate::getDay() const{ return day; }

int NonExistingDate::getMonth() const{ return month; }

int NonExistingDate::getYear() const{ return year; }


