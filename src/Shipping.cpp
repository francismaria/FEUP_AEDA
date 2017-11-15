/*
 * Shipping.cpp
 *
 *  Created on: 15/11/2017
 *      Author: Francisco
 */

#include "Shipping.h"

Shipping::Shipping(Date& b, Date& e, float w, int id): beggining(b), end(e), weight(w){}

Date& Shipping::getBeggining() const{ return beggining; }

Date& Shipping::getEnd() const{ return end; }


