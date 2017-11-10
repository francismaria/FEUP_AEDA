/*
 * MovingCompany.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "MovingCompany.h"
#include <algorithm>

MovingCompany::MovingCompany(std::string n, std::string d, int fd, int fm, int fy): foundingDate(Date(fd,fm,fy)){
	this->name = n;
	this->description = d;
}

std::string MovingCompany::getName() const{ return name; }

std::string MovingCompany::getDescription() const{ return description; }

const Date& MovingCompany::getFoundingDate() const{ return foundingDate; }

std::vector<Client*> MovingCompany::getClients() const{ return clients; }

void MovingCompany::addClient(Client* c){ clients.push_back(c); }

void MovingCompany::removeClient(std::string name){
	unsigned int i;

	for(i = 0; i < clients.size(); i++){
		if(clients[i]->getName() == name){
			clients.erase(clients.begin()+i);
			break;
		}
	}

	throw NonExistingClient(name);
}

void MovingCompany::printClientsByID() const{
	unsigned int i = 0;

	for(i = 0; i < clients.size(); i++){
		std::cout << *clients[i];
	}
}

// Uses Bubble Sort
void MovingCompany::printClientsByName() const{
	//Copies clients vector to another so it doesn't corrupt the original vector!!

	std::vector<Client*> clients_aux = clients;

	for(unsigned int j=clients_aux.size()-1; j>0; j--)
	{
		bool change = false;
		for(unsigned int i = 0; i < j; i++)
			if(clients_aux[i+1]->getName() < clients_aux[i]->getName()) {
				std::swap(clients_aux[i],clients_aux[i+1]);
				change = true;
			}
		if (!change) return;
	}

	for(unsigned int k = 0; k < clients_aux.size(); k++){
		std::cout << *clients_aux[k];
	}
}
/*
Client* median(std::vector<Client*>& c_aux, int left, int right){
	int center = (left+right) /2;

	if (c_aux[center]->getJoiningDate() < c_aux[left]->joiningDate)
		std::swap(c_aux[left], c_aux[center]);

	if (c_aux[right]->getJoiningDate() < c_aux[left]->getJoiningDate())
		std::swap(c_aux[left], c_aux[right]);

	if (c_aux[right]->getJoiningDate() < c_aux[center]->getJoiningDate())
		std::swap(c_aux[center], c_aux[right]);

	std::swap(c_aux[center], c_aux[right-1]);
	return c_aux[right-1];
}

void quicksort(std::vector<Client*>& c_aux, int left, int right){
	Client* c = median(c_aux, left, right);

	int i = left; int j = right-1; // passo de partição
	for(; ; ) {
		while (c_aux[++i] < c) ;
		while (c < c_aux[--j]) ;
		if (i < j)
			std::swap(c_aux[i], c_aux[j]);
		else break;
	}

	std::swap(c_aux[i], c_aux[right-1]); //repoe pivot
	quicksort(c_aux, left, i-1);
	quicksort(c_aux, i+1, right);
}*/

void selectionSort(std::vector<Client*> &c_aux )
{
	int min_idx, j;
	unsigned int i;
	std::vector<Client*>::iterator it;

	for(i = 0; i < c_aux.size(); i++){

		for(j = i+1; j < c_aux.size(); j++){
			if(c_aux[j]->getJoiningDate() < c_aux[i]->getJoiningDate()){
				Client* c = c_aux[i];
				c_aux[i] = c_aux[j];
				c_aux[j] = c;
			}
		}
	}
}

void MovingCompany::printClientsByJoiningDate() const{

	std::vector<Client*> clients_aux = clients;

	selectionSort(clients_aux);

	for(unsigned int i = 0; i < clients_aux.size(); i++){
		std::cout << *clients_aux[i];
	}
}





