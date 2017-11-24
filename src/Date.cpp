/*
 * Date.cpp
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / Jo�o Gama Amaral
 */

#include "Date.h"

Date::Date(int d, int m, int y): day(d), month(m), year(y){
	hour = 0;
	minute = 0;
}

Date::Date(int d, int m, int y, int h, int min): day(d), month(m), year(y), hour(h), minute(min){}

int Date::getDay() const{
	return day;
}

int Date::getMonth() const{
	return month;
}

int Date::getYear() const{
	return year;
}

int Date::getHour() const{
	return hour;
}

int Date::getMinute() const{
	return minute;
}

void Date::setDay(int d){
	day = d;
}

void Date::setMonth(int m){
	month = m;
}

void Date::setYear(int y){
	year = y;
}

void Date::setHour(int h){
	hour = h;
}

void Date::setMinute(int m){
	minute = m;
}



