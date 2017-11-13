/*
 * Service.h
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include "Libraries.h"
#include "Packaging.h"
#include "Shipping.h"
#include "Delivery.h"

typedef enum status {RECEIVED, PACKING, SHIPPED, ARRIVED_DEST, DELIVERED} Status;


class Service{
	int ID;
	Status status;
	float totalCost;
	float weight;
	//static int numberOfServicesDiff;		//WAREHOUSING NÃO E UM SERVIÇO DIFERENTE
public:
	Service(){};
	Service(int w);
	int getID() const;
	float getTotalCost() const;
	float getWeight() const;
	void setWeight() const;
	Status getStatus() const;
};

class Transport: public Service{
	Packaging* packaging;
	Shipping* shipping;
	Delivery* delivery;
	float cost;
public:
	Transport(){};
	Transport(Packaging* p, Shipping* s, float weight);
	float getTransportCost() const;
	const Date& getPackingBeggining() const;
	const Date& getPackingEnd() const;
	const Date& getServiceBeggining() const;
	const Date& getServiceEnd() const;
	const Date& getDeliveryBeggining() const;
	const Date& getDeliveryEnd() const;
	void setPackingBeggining();
	void setPackingEnd();
	void setServiceBeggining();
	void setServiceEnd();
	void setDeliveryBeggining();
	void setDeliveryEnd();
	void setShippingOrigin();
};

class Warehousing: public Service{

};





#endif /* SERVICE_H_ */
