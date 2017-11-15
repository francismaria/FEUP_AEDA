/*
 * Delivery.cpp
 *
 *  Created on: 15/11/2017
 *      Author: Francisco
 */

#include "Delivery.h"

Delivery::Delivery(Date& b, Date& e, float w, int id): beggining(b), end(e), weight(w){}

Date& Delivery::getBeggining(){ return beggining; }

Date& Delivery::getEnd(){ return end; }


