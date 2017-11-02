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





