/*
 * Service.h
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include "Libraries.h"
#include "Address.h"
#include "Date.h"
#include "Packaging.h"
#include "Shipping.h"
#include "Delivery.h"

typedef enum status {RECEIVED, PACKING, SHIPPED, ARRIVED_DEST, DELIVERED} Status;

class Service{
	int ID;
	float weight;
	Date beggining;
	Date end;
	Status status;
	Address origin;
	Address destination;
	Packaging* pack;
	Shipping* shipping;
	Delivery* delivery;
	static int numberOfServices;
public:
	Service(){}
	Service(Date& b, Date& e, int w);
	Service(Address& o, Address& d, float w, Date& b, Date& e);
	int getID();
	void setID(int id);
	Date& getBeggining();
	Date& getEnd();
	Status getStatus();
	float getWeight() const;
	static int getNumberOfServices();
	void setPackaging(Packaging* p);
	void setShipping(Shipping* s);
	void setDelivery(Delivery* d);
	Date& getPackagingBegginingDate() const;
	Date& getPackagingEndDate() const;
	Date& getShippingBegginingDate() const;
	Date& getShippingEndDate() const;
	Date& getDeliveryBegginingDate() const;
	Date& getDeliveryEndDate() const;
};

class Transport: public Service{
public:
	Transport(Address& o, Address& d, float w, Date& b, Date& e);
};

class Warehousing: public Transport{
	int daysWarehouse;
public:
	Warehousing(Address& o, Address& d, Date& b, Date& e, float w, int daysWarehouse);
	int getDaysWarehouse() const;
};



#endif /* SERVICE_H_ */
