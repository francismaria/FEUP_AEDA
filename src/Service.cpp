/*
 * Service.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Service.h"
/*
Service::Service(Date& b, float w): beggining(b), weight(w){ ID = 0; cost = 0; }

void Service::setID(int id){ ID = id; }

void Service::setCost(float c){ cost = c; }

float Service::getCost() const{ return cost; }
*/

/*
Service::Service(int w): weight(w) { status = RECEIVED; }

int Service::getID() const{ return ID; }

float Service::getTotalCost() const{ return totalCost; }

float Service::getWeight() const{ return weight; }


Transport::Transport(Address& o, Address& d, float weight): origin(o), destination(d), Service(weight){}

const Date& Transport::getPackingBeggining() const{ return this->packaging->getBegginingDate(); }

float Transport::getShippingCost() const{ return shipping->getTax(); }
*/

/************************** SERVICE ******************************/

int Service::numberOfServices = 1;

Service::Service(int id): ID(id){}

Service::Service(Address& o, Address& d, float w): origin(o), destination(d), weight(w){
	status = RECEIVED;
	this->ID = numberOfServices;
	numberOfServices++;
}

Service::Service(Address& o, Address& d, float w, int id): origin(o), destination(d), weight(w), ID(id){
	status = RECEIVED;
}

Service::Service(Date& b, Date& e, int w): weight(w){
	this->beggining = b;
	this->end = end;
}

Service::Service(Address& o, Address& d, float w, Date& b, Date& e): origin(o), destination(d), weight(w), beggining(b), end(e){
	this->ID = numberOfServices;
	numberOfServices++;
}

int Service::getID() {
	return ID;
}
float Service::getWeight() {
	return weight;
}
Address& Service::getOrigin() {
	return origin;
}
Address& Service::getDestination(){
	return destination;
}
Date& Service::getBeggining() {
	return beggining;
}
Date& Service::getEnd(){
	return end;
}
Status Service::getStatus() {
	return status;
}

void Service::setID(int id){
	ID = id;
}

int Service::getNumberOfServices(){
	return numberOfServices;
}

/******************* TRANSPORT **************************/
//Transport::Transport(Address& o, Address& d, float w): Service(o, d, w){}

Transport::Transport(Address& o, Address& d, float w, Date& b, Date& e): Service(o,d,w,b,e){}



/************SHIPPING*****************/

Shipping::Shipping(Address& o, Address& d, float w,/*, Date& b, Date& e*/ int id): Service(o, d, w){}

Shipping::Shipping(Address& o, Address& d, float w, Date& b, Date& e, int id): Service(o, d, w, b, e){}

Shipping::Shipping(Date& b, Date& e, int w): Service(b,e,w){}

float Shipping::getTax() const{ return tax; }


/***********PACKAGING****************/

Packaging::Packaging(Date& b, Date& e, int w): Service(b,e,w){}

Packaging::Packaging(Date& b, int id): Service(id){
	getBeggining() = b;
}

void Packaging::setBegginingDate(Date& d){
	this->getBeggining() = d;
}

void Packaging::setEndDate(Date& d){
	this->getEnd() = d;
}

/*********************DELIVERY**********/

Delivery::Delivery(int id): Service(id){}

Delivery::Delivery(Date& b, Date& e, int w): Service(b,e,w){}
