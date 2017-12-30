/*
 * Vehicle.cpp
 *
 *  Created on: 27/12/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Vehicle.h"

int Vehicle::numberOfVehicles = 0;

Vehicle::Vehicle(int ID, float maxW): id(ID), maxWeight(maxW){
	numberOfVehicles++;
}

int Vehicle::getID() const{
	return id;
}

float Vehicle::getMaxWeight() const{
	return maxWeight;
}

int Vehicle::getNumberOfVehicles(){
	return numberOfVehicles;
}

bool Vehicle::operator ==(const Vehicle& v){
	if(id == v.getID())
		return true;
	return false;
}

