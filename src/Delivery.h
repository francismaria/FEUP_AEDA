/*
 * Delivery.h
 *
 *  Created on: 12/11/2017
 *      Author: Francisco
 */

#ifndef DELIVERY_H_
#define DELIVERY_H_

#include "Libraries.h"
#include "Address.h"
#include "Date.h"

class Delivery{
	Date beggining;
	Date end;
public:
	Delivery(){};
	const Date& getBeggining() const;
	const Date& getEnd() const;
};



#endif /* DELIVERY_H_ */
