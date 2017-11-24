/*
 * Service.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Service.h"

/*****************************************************************/
/************************** SERVICE ******************************/
/*****************************************************************/

int Service::numberOfServices = 1;

Service::~Service(){
	delete(pack);
	delete(shipping);
	delete(delivery);
	delete(payment);
}

Service::Service(Address& o, Address& d, float w, Date& b, Date& e): origin(o), destination(d), weight(w), beggining(b), end(e), totalCost(0){
	this->ID = numberOfServices;
	numberOfServices++;
}

void Service::addBaseRate(float baseRate){
	this->totalCost += baseRate;
}

int Service::getID() {
	return ID;
}
float Service::getWeight() const{
	return weight;
}

float Service::getTotalCost() const{
	return totalCost;
}

Date& Service::getBeggining() {
	return beggining;
}
Date& Service::getEnd(){
	return end;
}

Address& Service::getOrigin(){
	return origin;
}

Address& Service::getDestination(){
	return destination;
}

void Service::setID(int id){
	ID = id;
}

int Service::getNumberOfServices(){
	return numberOfServices;
}
void Service::setPackaging(Packaging* p){
	this->pack = p;
	this->totalCost += p->getCost();
}

void Service::setShipping(Shipping* s){
	this->shipping = s;
	this->totalCost += s->getCost();
}

void Service::setDelivery(Delivery* d){
	this->delivery = d;
	this->totalCost += d->getCost();
}

void Service::setPayment(Payment* pay){
	this->payment = pay;
	this->totalCost += (this->totalCost*pay->getPaymentTax());
}

Payment* Service::getPayment() const{
	return payment;
}

Date& Service::getPackagingBegginingDate() const{
	return this->pack->getBeggining();
}

Date& Service::getPackagingEndDate() const{
	return this->pack->getEnd();
}

Date& Service::getShippingBegginingDate() const{
	return this->shipping->getBeggining();
}

Date& Service::getShippingEndDate() const{
	return this->shipping->getEnd();
}

Date& Service::getDeliveryBegginingDate() const{
	return this->delivery->getBeggining();
}

Date& Service::getDeliveryEndDate() const{
	return this->delivery->getEnd();
}

void Service::validatePayment(){
	this->payment->validate();
}

/********************************************************/
/******************* TRANSPORT **************************/
/********************************************************/

Transport::Transport(Address& o, Address& d, float w, Date& b, Date& e): Service(o, d, w, b, e){}


/********************************************************/
/******************* WAREHOUSING ************************/
/********************************************************/

Warehousing::Warehousing(Address& o, Address& d, float w, Date& b, Date& e, int daysWarehouse): Transport(o,d,w,b,e){
	this->daysWarehouse = daysWarehouse;

	if(this->daysWarehouse > 5){
		float tax = w * TAX_WAREHOUSING_DAY;
		this->addBaseRate((this->daysWarehouse - 5) * tax);
	}
}

int Warehousing::getDaysWarehouse() const{
	return daysWarehouse;
}

