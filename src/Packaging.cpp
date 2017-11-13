/*
 * Packaging.cpp
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria João Gama Amaral
 */

#include "Packaging.h"

Packaging::Packaging(Date& b): beggining(b){}

const Date& Packaging::getBegginingDate() const{ return beggining; }

const Date& Packaging::getEndDate() const{ return end; }




