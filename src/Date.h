/*
 * Date.h
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef DATE_H_
#define DATE_H_

#include "Libraries.h"

class Date{
	int day;
	int month;
	int year;
	int hour;
	int minute;
public:
	Date(){};
	Date(int d, int m, int y);
	Date(int d, int m, int y, int h, int min);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	int getHour() const;
	int getMinute() const;
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void setHour(int h);
	void setMinute(int m);
	friend bool operator ==(const Date& d, const Date& d1){
		if(d.day == d1.getDay() && d.month == d1.getMonth() && d.year == d1.getYear())
			return true;
		return false;
	}

	friend std::ostream& operator <<(std::ostream& o, const Date& d){
		o << d.day << "/" << d.month << "/" << d.year << " " << d.hour << ":" << d.minute;
		return o;
	}

	friend bool operator <(const Date& d1, const Date& d2){
		if(d1.year < d2.getYear())
				return true;
			else if(d1.year > d2.getYear())
				return false;

			if(d1.month < d2.getMonth())
				return true;
			else if(d1.month > d2.getMonth())
				return false;

			if(d1.day < d2.getDay())
				return true;
			return false;
	}
};




#endif /* DATE_H_ */
