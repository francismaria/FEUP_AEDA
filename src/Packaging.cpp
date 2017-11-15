/*
 * Packaging.cpp
 *
 *  Created on: 15/11/2017
 *      Author: Francisco
 */

#include "Packaging.h"

Packaging::Packaging(Date& b, Date& e, float w, int id): beggining(b), end(e), weight(w){}

Date& Packaging::getBeggining(){ return beggining; }

Date& Packaging::getEnd(){ return end; }


