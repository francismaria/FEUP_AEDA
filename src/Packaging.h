/*
 * Packaging.h
 *
 *  Created on: 15/11/2017
 *      Author: Francisco
 */

#ifndef PACKAGING_H_
#define PACKAGING_H_

#include "Libraries.h"
#include "Date.h"

const float TAX_PACKAGING = 0.045; 	//4.5%

class Packaging{
	float cost;
	Date beggining;
	Date end;
	float weight;
public:
	Packaging(Date& b, Date& e, float w, int id);
	Date& getBeggining();
	Date& getEnd();
	float getCost() const;
};




#endif /* PACKAGING_H_ */
