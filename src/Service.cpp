/*
 * Service.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Service.h"

Service::Service(int w): weight(w) { status = RECEIVED; }

int Service::getID() const{ return ID; }

float Service::getTotalCost() const{ return totalCost; }

float Service::getWeight() const{ return weight; }


Transport::Transport(Packaging* p, Shipping* s, float weight): packaging(p), shipping(s), Service(weight){}

const Date& Transport::getPackingBeggining() const{ return this->packaging->getBegginingDate(); }

float Transport::getShippingCost() const{ return shipping->getCost(); }
