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
	friend std::ostream& operator <<(std::ostream& o, const Service& s){
		o << "Service Info:\n" << "ID: " << s.ID << "\nOrigin: " << s.end;
		return o;
	}
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
	Warehousing(Address& o, Address& d, Date& b, Date& e, float w, int daysWarehouse);
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

#endif /* SERVICE_H_ */
