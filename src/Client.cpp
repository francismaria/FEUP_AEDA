/*
 * Client.cpp
 *
 *  Created on: 01/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Client.cpp"

int Client::numberOfClients = 0;

/*
 * Client constructor
 */

Client::Client(int id, int age, std::string name, long int nif, std::string address){
	this->id = id;
	this->age = age;
	this->name = name;
	this->NIF = nif;
	this->address = address;
	numberOfClients++;
}

int Client::getId() const{ return id; }

int Client::getAge() const{ return age; }

long int Client::getNIF() const{ return NIF; }

std::string Client::getName() const{ return name; }

std::string Client::getAddress() const{ return address; }





