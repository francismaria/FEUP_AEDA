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

class Delivery{
	float weight;
	Date& beggining;
	Date& end;
public:
	Delivery(Date& b, Date& e, float w, int id);
	Date& getBeggining() const;
	Date& getEnd() const;
};



#endif /* DELIVERY_H_ */
