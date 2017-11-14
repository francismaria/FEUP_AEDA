/*
 * ImportInfo.h
 *
 *  Created on: 14/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef IMPORTINFO_H_
#define IMPORTINFO_H_

#include "Libraries.h"
#include "Interface.h"
#include <fstream>

void importClients(MovingCompany& company);

void importCountries(MovingCompany& company);

void importCountriesZones(MovingCompany& company);

void importServices(MovingCompany& company);


#endif /* IMPORTINFO_H_ */
