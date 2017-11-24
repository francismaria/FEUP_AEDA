/*
 * Algorithms.h
 *
 *  Created on: 24/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

#include "Libraries.h"
#include "Client.h"

void bubbleSort(std::vector<Client*>& clients_aux);

void selectionSort(std::vector<Client*> &c_aux);

int binarySearch(const std::vector<Client*> &v, int x);

int binarySearch(const std::vector<Client*> &v, std::string x);



#endif /* ALGORITHMS_H_ */
