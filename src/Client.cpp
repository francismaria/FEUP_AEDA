/*
 * Client.cpp
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Client.h"

int Client::numberOfClients = 0;

/************************************************/
/************  CLIENT CONTRUCTOR  ***************/
/************************************************/

Client::Client(std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute):
				address(Address(address, zipCode, city, country)), joiningDate(Date(firstDay, firstMonth, firstYear, hour, minute)){
	numberOfClients++;
	this->id = numberOfClients;
	this->name = name;
	this->NIF = nif;
}

int Client::getId() const{
	return id;
}

long int Client::getNIF() const{
	return NIF;
}

std::string Client::getName() const{
	return name;
}

const Address& Client::getAddress() const{
	return address;
}

std::string Client::getZipCode() const{
	return address.getZipCode();
}

bool Client::operator ==(const Client& c1){
	if(this->id == c1.getId() && this->name == c1.getName()) return true;
	return false;
}

const Date& Client::getJoiningDate() const{
	return joiningDate;
}

std::vector<Service*> Client::getServicesRequested(){
	return servicesRequested;
}

void Client::addNewService(Service* s){
	servicesRequested.push_back(s);
}

int Client::getNumberOfClients(){
	return numberOfClients;
}

void Client::printServices() const{

	unsigned int i;

	for(i = 0; i < servicesRequested.size(); i++){
		std::cout << *servicesRequested[i];
	}
}

void Client::checkServiceStatus(int sID) const{

	std::cout << "STATUS: " << servicesRequested[sID-1]->getPayment()->getPaymentStatus();
}

void Client::validatePayment(int sID){

	servicesRequested[sID-1]->validatePayment();

	//throw not existing service
}

/************************************************/
/************  COMPANY CONTRUCTOR  **************/
/************************************************/

int Company::numberOfCompanies = 0;

Company::Company(std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute)
: Client(name, nif, address, zipCode, city, country, firstDay, firstMonth, firstYear, hour, minute){
	numberOfCompanies++;
}

int Company::getNumberOfCompanies(){
	return numberOfCompanies;
}

bool Company::isParticular(){
	return false;
}


/************************************************/
/**********  PARTICULAR CONTRUCTOR  *************/
/************************************************/

int Particular::numberOfParticulars = 0;

Particular::Particular(std::string name, int age, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute)
: Client(name, nif, address, zipCode, city, country, firstDay, firstMonth, firstYear, hour, minute){
	this->age = age;
	numberOfParticulars++;
}

int Particular::getAge(){
	return age;
}

bool Particular::isParticular(){
	return true;
}

int Particular::getNumberOfParticulars(){
	return numberOfParticulars;
}









