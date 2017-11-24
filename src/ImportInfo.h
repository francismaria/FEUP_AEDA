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
#include "Algorithms.h"
#include <fstream>
#include <ctime>

/**
 * @brief import clients from .txt file
 * @param company company itself
 * @param numberofExistentClients number of already existent clients
 */
void importClients(MovingCompany& company, int& numberofExistentClients);

/**
 * @brief import countries from .txt file
 * @param company company itself
 */
void importCountries(MovingCompany& company);

/**
 * @brief import countries zones from .txt file
 * @param company company itself
 */
void importCountriesZones(MovingCompany& company);

/**
 * @brief import services from .txt file
 * @param company company itself
 */
void importServices(MovingCompany& company);


#endif /* IMPORTINFO_H_ */
