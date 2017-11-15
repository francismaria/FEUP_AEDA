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

class Shipping{
	float weight;
	Date& beggining;
	Date& end;
public:
	Shipping(Date& b, Date& e, float w, int id);
	Date& getBeggining() const;
	Date& getEnd() const;
};


#endif /* SHIPPING_H_ */
