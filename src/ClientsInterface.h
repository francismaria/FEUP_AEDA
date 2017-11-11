/*
 * ClientsInterface.h
 *
 *  Created on: 11/11/2017
 *      Author: Francisco
 */

#ifndef CLIENTSINTERFACE_H_
#define CLIENTSINTERFACE_H_

#include "MovingCompany.h"
#include <ctime>

int checkClient(MovingCompany& company);

int addNewClient(MovingCompany& company);

int removeClient(MovingCompany& company);

int printParticulars(MovingCompany& company);

int printCompanies(MovingCompany& company);

int printClients(MovingCompany& company);



#endif /* CLIENTSINTERFACE_H_ */
