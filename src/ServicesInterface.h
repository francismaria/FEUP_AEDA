/*
 * ServicesInterface.h
 *
 *  Created on: 10/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef SERVICESINTERFACE_H_
#define SERVICESINTERFACE_H_

#include "MovingCompany.h"
#include <ctime>

int newService(MovingCompany& company);

int newRegisteredClientService(MovingCompany& company);

int newUnregisteredClientService(MovingCompany& company);

int printClientsServices(MovingCompany& company);

#endif /* SERVICESINTERFACE_H_ */
