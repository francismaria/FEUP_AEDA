/*
 * ExportInfo.h
 *
 *  Created on: 16/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef EXPORTINFO_H_
#define EXPORTINFO_H_

#include "Libraries.h"
#include "MovingCompany.h"
#include <fstream>

void saveClients(MovingCompany& company, int newClients);

void saveServices(MovingCompany& company);

#endif /* EXPORTINFO_H_ */
