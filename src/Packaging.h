/*
 * Packaging.h
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef PACKAGING_H_
#define PACKAGING_H_

#include "Libraries.h"
#include "Date.h"

class Packaging{
	Date beggining;
	Date end;
public:
	Packaging(){};
	Packaging(Date& b);
	void setBegginingDate(Date& d);
	void setEndDate(Date& d);
	const Date& getBegginingDate() const;
	const Date& getEndDate() const;
};



#endif /* PACKAGING_H_ */
