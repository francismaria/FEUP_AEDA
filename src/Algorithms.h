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

/**
 * @brief uses bubble sort to sort a vector by ID
 * @param clients_aux clients vector to be sorted
 */
void bubbleSort(std::vector<Client*>& clients_aux);

/**
 * @brief uses selection sort to sort a vector by joining date
 * @param c_aux clients vector to be sorted
 */
void selectionSort(std::vector<Client*> &c_aux);

/**
 * @brief uses binary search to search a client by ID
 * @param v clients vector to search
 * @param clients ID
 */
int binarySearch(const std::vector<Client*> &v, int x);

/**
 * @brief uses binary search to search a client by name
 * @param v clients vector to search
 * @param clients name
 */
int binarySearch(const std::vector<Client*> &v, std::string x);



#endif /* ALGORITHMS_H_ */
