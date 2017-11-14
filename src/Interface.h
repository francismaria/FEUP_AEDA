/*
 * Interface.h
 *
 *  Created on: 02/11/2017
 *      Author: Francisco
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "MovingCompany.h"
#include "ClientsInterface.h"
#include "ServicesInterface.h"

void run(MovingCompany& company);

int showMenu(MovingCompany& company);

bool showClientsMenu(MovingCompany& company);

bool showServicesMenu(MovingCompany& company);

#endif /* INTERFACE_H_ */
