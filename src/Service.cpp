/*
 * Service.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Service.h"

/************************** SERVICE ******************************/

int Service::numberOfServices = 1;

Service::Service(Date& b, Date& e, int w): weight(w){
	this->beggining = b;
	this->end = end;
	this->ID = numberOfServices;
	numberOfServices++;
}

Service::~Service(){
	delete(pack);
	delete(shipping);
	delete(delivery);
}

Service::Service(Address& o, Address& d, float w, Date& b, Date& e): origin(o), destination(d), weight(w), beggining(b), end(e){
	this->ID = numberOfServices;
	numberOfServices++;
}

int Service::getID() {
	return ID;
}
float Service::getWeight() const{
	return weight;
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
void Service::setPackaging(Packaging* p){
	this->pack = p;
}

void Service::setShipping(Shipping* s){
	this->shipping = s;
}

void Service::setDelivery(Delivery* d){
	this->delivery = d;
}

Date& Service::getPackagingBegginingDate() const{
	this->pack->getBeggining();
}

Date& Service::getPackagingEndDate() const{
	this->pack->getEnd();
}

Date& Service::getShippingBegginingDate() const{
	this->shipping->getBeggining();
}

Date& Service::getShippingEndDate() const{
	this->shipping->getEnd();
}

Date& Service::getDeliveryBegginingDate() const{
	this->delivery->getBeggining();
}

Date& Service::getDeliveryEndDate() const{
	this->delivery->getEnd();
}

/******************* TRANSPORT **************************/

Transport::Transport(Address& o, Address& d, float w, Date& b, Date& e): Service(o, d, w, b, e){}



/******************* WAREHOUSING ************************/

Warehousing::Warehousing(Address& o, Address& d, Date& b, Date& e, float w, int daysWarehouse): Transport(o,d,w,b,e){
	this->daysWarehouse = daysWarehouse;
}

