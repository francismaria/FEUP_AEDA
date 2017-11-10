/*
 * MovingCompany.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "MovingCompany.h"

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
	//Copies clients vector to another!!

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

	//ordenar por nome
}

void MovingCompany::printClientsByJoiningDate() const{
	//ordenar por data
}





