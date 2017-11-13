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
/*
MovingCompany::MovingCompany(std::string n, std::string d, int fd, int fm, int fy, std::vector<Country*> countries):
		foundingDate(Date(fd,fm,fy)), countriesToOperate(countries){
	this->name = n;
	this->description = d;
}*/

std::string MovingCompany::getName() const{ return name; }

std::string MovingCompany::getDescription() const{ return description; }

const Date& MovingCompany::getFoundingDate() const{ return foundingDate; }

std::vector<Client*> MovingCompany::getClients() const{ return clients; }

std::vector<Client*> MovingCompany::getParticularClients() const{

	unsigned int i;
	std::vector<Client*> particulars_aux;

	for(i = 0; i < clients.size(); i++){
		if(clients[i]->isParticular()){
			particulars_aux.push_back(clients[i]);
		}
	}
	return particulars_aux;
}

std::vector<Client*> MovingCompany::getCompaniesClients() const{
	unsigned int i;
	std::vector<Client*> companies_aux;

	for(i = 0; i < clients.size(); i++){
		if(!clients[i]->isParticular()){
			companies_aux.push_back(clients[i]);
		}
	}
	return companies_aux;
}

void MovingCompany::addClient(Client* c){ clients.push_back(c); }

void MovingCompany::addCountry(Country* c){ countriesToOperate.push_back(c); }

std::vector<Country*> MovingCompany::getCountriesToOperate() const{ return countriesToOperate; }

void MovingCompany::printAllCountriesToOperate() const{

	for(unsigned int i = 0; i < countriesToOperate.size(); i++){
		std::cout << "\t\t\t\t\t\t\t" << i+1 << " - " << countriesToOperate[i] << std::endl;
	}
}

void MovingCompany::printCountriesToOperateFrom(Country* c){ c->printZoneCountries(); }

Country* MovingCompany::getCountryDestination(Country* c, int id){ return c->getDestination(id); }

//  -- BINARY SEARCH
int binarySearch(const std::vector<Client*> &v, int x)
{
	int left = 0, right = v.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (v[middle]->getId() < x)
			left = middle + 1;
		else if (x < v[middle]->getId())
			right = middle-1;
		else
			return middle; // encontrou
	}
	return -1; // não encontrou
}

int binarySearch(const std::vector<Client*> &v, std::string x)
{
	int left = 0, right = v.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (v[middle]->getName() < x)
			left = middle + 1;
		else if (x < v[middle]->getName())
			right = middle-1;
		else
			return middle; // encontrou
	}
	return -1; // não encontrou
}

void MovingCompany::removeClientByID(int id){

	int index = binarySearch(clients, id);

	if(index == -1){
		//throw NonExisting Client();
		std::cout << "NÃO EXISTE!" << std::endl;
	}
	clients.erase(clients.begin()+index);
}

void MovingCompany::removeClientByName(std::string name){
	bool found = false;
	unsigned int i;

	for(i = 0; i < clients.size(); i++){
		if(clients[i]->getName() == name){
			found = true;
			break;
		}
	}

	if(found) std::cout << "ENCOTROU!";
	else std::cout << "NÃO ENCONTROU!";
	//if(found) clients.erase(clients.begin()+i);
	//else std::cout << "nao encontrou";

	//throw NonExistingClient(name);
}


void MovingCompany::removeClientByJoiningDate(int d, int m, int y){

	//int n;
	unsigned int i;
	Date date(d, m, y);

	for(i = 0; i < clients.size(); i++){
		if(clients[i]->getJoiningDate() == date){
			clients.erase(clients.begin()+i);
			return;
		}
	}

	//throw NonExistingDate(d, m, y);
	//std::cout << "Data nao existente";
}

void MovingCompany::printClient(std::string name) const{

	int index = binarySearch(clients, name);

	if(index == -1){
		//throw...
		std::cout << "There is no client with that name." << std::endl;
	}

	std::cout << *clients[index];
}

void MovingCompany::printClient(int id) const{

	std::cout << *clients[id-1];
}


// ----- PRINT CLIENTS INFO

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


//  GENERAL PRINT
void MovingCompany::printByID(std::vector<Client*>& clients_aux) const{
	unsigned int i;

	for(i = 0; i < clients_aux.size(); i++){
		std::cout << *clients_aux[i];
	}
}

// Uses Bubble Sort
void MovingCompany::printByName(std::vector<Client*>& clients_aux) const{

	bubbleSort(clients_aux);

	for(unsigned int k = 0; k < clients_aux.size(); k++){
		std::cout << *clients_aux[k];
	}
}

// Uses Selection Sort
void MovingCompany::printByJoiningDate(std::vector<Client*>& clients_aux) const{

	selectionSort(clients_aux);

	for(unsigned int i = 0; i < clients_aux.size(); i++){
		std::cout << *clients_aux[i];
	}
}


// ---- ALL CLIENTS ----- //

void MovingCompany::printClientsByID() const{

	std::vector<Client*> clients_aux = clients;

	printByID(clients_aux);
}


void MovingCompany::printClientsByName() const{

	std::vector<Client*> clients_aux = clients;

	printByName(clients_aux);
}

void MovingCompany::printClientsByJoiningDate() const{

	std::vector<Client*> clients_aux = clients;

	printByJoiningDate(clients_aux);

}

// ----- PARTICULAR CLIENTS ------- //

void MovingCompany::printParticularClientsByID() const{

	std::vector<Client*> particulars_aux = getParticularClients();

	printByID(particulars_aux);
}

void MovingCompany::printParticularClientsByName() const{

	std::vector<Client*> particulars_aux = getParticularClients();

	printByName(particulars_aux);
}

void MovingCompany::printParticularClientsByJoiningDate() const{

	std::vector<Client*> particulars_aux = getParticularClients();

	printByJoiningDate(particulars_aux);
}

// ----- COMPANIES CLIENTS ------ //

void MovingCompany::printCompanyClientsByID() const{

	std::vector<Client*> companies_aux = getCompaniesClients();

	printByID(companies_aux);
}

void MovingCompany::printCompanyClientsByName() const{

	std::vector<Client*> companies_aux = getCompaniesClients();

	printByName(companies_aux);
}

void MovingCompany::printCompanyClientsByJoiningDate() const{

	std::vector<Client*> companies_aux = getCompaniesClients();

	printByJoiningDate(companies_aux);
}


