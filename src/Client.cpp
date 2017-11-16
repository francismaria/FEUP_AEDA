/*
 * Client.cpp
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Client.h"

int Client::numberOfClients = 0;

/*
 *  Client constructor
 */
//TO BE DELETED
Client::Client(std::string name, long int nif, std::string address, std::string zipCode, int firstDay, int firstMonth, int firstYear):
				address(Address(address, zipCode, "Porto", "Portugal")), joiningDate(Date(firstDay, firstMonth, firstYear)){
	numberOfClients++;
	this->id = numberOfClients;
	this->name = name;
	this->NIF = nif;
}

Client::Client(std::string name, long int nif, std::string address, std::string zipCode, std::string city, int firstDay, int firstMonth, int firstYear, int hour, int minute):
				address(Address(address, zipCode, city, "Portugal")), joiningDate(Date(firstDay, firstMonth, firstYear, hour, minute)){
	numberOfClients++;
	this->id = numberOfClients;
	this->name = name;
	this->NIF = nif;
}

int Client::getId() const{ return id; }

long int Client::getNIF() const{ return NIF; }

std::string Client::getName() const{ return name; }

const Address& Client::getAddress() const{ return address; }

std::string Client::getZipCode() const{ return address.getZipCode(); }

bool Client::operator ==(const Client& c1){
	if(this->id == c1.getId() && this->name == c1.getName()) return true;
	return false;
}

const Date& Client::getJoiningDate() const{ return joiningDate; }

std::vector<Service*> Client::getServicesRequested(){ return servicesRequested; }

void Client::addNewService(Service* s){ servicesRequested.push_back(s); }

int Client::getNumberOfClients(){ return numberOfClients; }

void Client::printServices() const{

	unsigned int i;

	for(i = 0; i < servicesRequested.size(); i++){
		std::cout << servicesRequested[i]->getID();//->getOrigin().getCity();//->getOrigin();
	}
}
/*
 * Company Constructor
 */

int Company::numberOfCompanies = 0;

Company::Company(std::string name, long int nif, std::string address, std::string zipCode, std::string city, int firstDay, int firstMonth, int firstYear, int hour, int minute)
: Client(name, nif, address, zipCode, city, firstDay, firstMonth, firstYear, hour, minute){
	numberOfCompanies++;
}

int Company::getNumberOfCompanies(){ return numberOfCompanies; }

bool Company::isParticular(){ return false; }


/*
 *  Particular constructor
 */

int Particular::numberOfParticulars = 0;

//TO BE DELETED
Particular::Particular(std::string name, int age, long int nif, std::string address, std::string zipCode, int firstDay, int firstMonth, int firstYear)
: Client(name, nif, address, zipCode, firstDay, firstMonth, firstYear){
	this->age = age;
	numberOfParticulars++;
}

Particular::Particular(std::string name, int age, long int nif, std::string address, std::string zipCode, std::string city, int firstDay, int firstMonth, int firstYear, int hour, int minute)
: Client(name, nif, address, zipCode, city, firstDay, firstMonth, firstYear, hour, minute){
	this->age = age;
	numberOfParticulars++;
}

int Particular::getAge() const{ return age; }

bool Particular::isParticular(){ return true; }

int Particular::getNumberOfParticulars(){ return numberOfParticulars; }









