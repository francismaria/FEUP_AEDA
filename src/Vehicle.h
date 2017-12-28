/*
 * Vehicle.h
 *
 *  Created on: 26/12/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "Libraries.h"

/**
 * @brief Class that handles all vehicle information
 */
class Vehicle{
	int id;
	float maxWeight;
	static int numberOfVehicles;
public:
	/**
	 * @brief Vehicle Constructor
	 * @param ID id of the vehicle
	 * @param maxW max weight of the vehicle
	 */
	Vehicle(int ID, float maxW);

	/**
	 * @brief Gets vehicle ID
	 * @return ID of the vehicle
	 */
	int getID() const;

	/**
	 * @brief Gets max weight of cargo of the vehicle
	 * @return Max weight of the vehicle
	 */
	float getMaxWeight() const;

	/**
	 * @brief Gets number of vehicles
	 * @rturn Number of vehicles
	 */
	static int getNumberOfVehicles();
};



#endif /* VEHICLE_H_ */
