/*
 * Delivery.h
 *
 *  Created on: 15/11/2017
 *      Author: Francisco
 */

#ifndef DELIVERY_H_
#define DELIVERY_H_

#include "Libraries.h"
#include "Date.h"

const float TAX_DELIVERY = 0.01;		// 1%

class Delivery{
	float cost;
	Date beggining;
	Date end;
	float weight;
public:
	Delivery(Date& b, Date& e, float w, int id);
	Date& getBeggining();
	Date& getEnd();
	float getCost() const;
};



#endif /* DELIVERY_H_ */
