/*
 * Shipping.h
 *
 *  Created on: 15/11/2017
 *      Author: Francisco
 */

#ifndef SHIPPING_H_
#define SHIPPING_H_

#include "Libraries.h"
#include "Date.h"

const float TAX_SHIPPING = 0.075;

class Shipping{
	float cost;
	Date beggining;
	Date end;
	float weight;
public:
	Shipping(Date& b, Date& e, float w, int id);
	~Shipping(){};
	Date& getBeggining();
	Date& getEnd();
	float getCost() const;
};


#endif /* SHIPPING_H_ */
