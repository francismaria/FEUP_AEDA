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

typedef enum status {RECEIVED, PACKING, SHIPPED, ARRIVED_DEST, DELIVERED} Status;

class Service{
	int ID;
	float weight;
	Address origin;
	Address destination;
	Date beggining;
	Date end;
	Status status;
	static int numberOfServices;
public:
	Service(){}
	Service(int id);
	Service(Date& b, Date& e, int w);
	Service(Address& o, Address& d, float w);
	Service(Address& o, Address& d, float w, int id);
	Service(Address& o, Address& d, float w, Date& b, Date& e);
	int getID();
	void setID(int id);
	float getWeight() ;
	Address& getOrigin() ;
	Address& getDestination() ;
	Date& getBeggining() ;
	Date& getEnd() ;
	Status getStatus() ;
	static int getNumberOfServices();
};

class Transport: public Service{
public:
	Transport(Address& o, Address& d, float w, Date& b, Date& e);
	float getWeight() const;
};

class Warehousing: public Transport{
	int daysWarehouse;
	float weight;
public:
	Warehousing(Address& o, Address& d, float weight, int daysWarehouse);
	int getDaysWarehouse() const;
};

class Packaging: public Service{
public:
	Packaging(): Service(){};
	Packaging(Date& b, Date& e, int weight);
	Packaging(Date& b, int id);
	void setBegginingDate(Date& d);
	void setEndDate(Date& d);
};

class Shipping: public Service{
	float tax;
public:
	Shipping(){};
	Shipping(Date& b, Date& e, int weight);
	Shipping(Address& o, Address& d, float w, int id);
	Shipping(Address& o, Address& d, float w, Date& b, Date& e, int id);
	float getTax() const;
	void setBegginingDate(Date& d);
	void setEndDate(Date& d);
};

class Delivery: public Service{
public:
	Delivery(){};
	Delivery(Date& b, Date& e, int weight);
	Delivery(int id);
	void setBegginingDate(Date& d);
	void setEndDate(Date& d);
};



/*
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
	//Warehousing* now;
	Address origin;
	Address destination;
	// ------------------
	float cost;
public:
	Transport(Address& o, Address& d, float weight);
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
	float getShippingCost() const;
};

class Warehousing: public Transport{

};*/





#endif /* SERVICE_H_ */
