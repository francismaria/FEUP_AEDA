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

class Packaging{
	float weight;
	Date& beggining;
	Date& end;
public:
	Packaging(Date& b, Date& e, float w, int id);
	Date& getBeggining() const;
	Date& getEnd() const;
};




#endif /* PACKAGING_H_ */
