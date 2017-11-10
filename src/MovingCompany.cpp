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

void bubbleSort(std::vector<Client*>& clients_aux){

	for(unsigned int j=clients_aux.size()-1; j > 0; j--)
	{
		bool change = false;
		for(unsigned int i = 0; i < j; i++)
			if(clients_aux[i+1]->getName() < clients_aux[i]->getName()) {
				std::swap(clients_aux[i],clients_aux[i+1]);
				change = true;
			}
		if (!change) return;
	}
}

// Uses Bubble Sort
void MovingCompany::printClientsByName() const{
	//Copies clients vector to another so it doesn't corrupt the original vector!!

	std::vector<Client*> clients_aux = clients;

	bubbleSort(clients_aux);

	for(unsigned int k = 0; k < clients_aux.size(); k++){
		std::cout << *clients_aux[k];
	}
}

void selectionSort(std::vector<Client*> &c_aux )
{
	int j, i;
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





