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
#include "Payment.h"

const float TAX_WAREHOUSING_DAY = 0.01;		//  1%

/**
 * @brief Class that stores all service information
 */
class Service{
	int ID;
	float weight;
	Date beggining;
	Date end;
	Address origin;
	Address destination;
	Packaging* pack;
	Shipping* shipping;
	Delivery* delivery;
	Payment* payment;
	float totalCost;
	static int numberOfServices;
public:
	/**
	 * Service Default Contructor
	 */
	Service(){}

	/**
	 * Service Default Destructor
	 */
	~Service();

	/**
	 * Service Constructor
	 */
	Service(Address& o, Address& d, float w, Date& b, Date& e);

	/**
	 * @brief adds base rate to service
	 * @param baseRate base rate of the country destination service
	 */
	void addBaseRate(float baseRate);

	/**
	 * @return service ID
	 */
	int getID();

	/**
	 * @brief sets ID
	 * @param id ID to be set
	 */
	void setID(int id);

	/**
	 * @brief gets service request date
	 * @return date
	 */
	Date& getBeggining();

	/**
	 * @brief gets service ending date
	 * @return date
	 */
	Date& getEnd();

	/**
	 * @brief gets origin address
	 * @return address
	 */
	Address& getOrigin();

	/**
	 * @brief gets destination address
	 * @return address
	 */
	Address& getDestination();

	/**
	 * @brief gets payment
	 * @return payment
	 */
	Payment* getPayment() const;

	/**
	 * @return weight of the package
	 */
	float getWeight() const;

	/**
	 * @return total cost of the service
	 */
	float getTotalCost() const;

	/**
	 * @return total amount of services
	 */
	static int getNumberOfServices();

	/**
	 * @brief sets packaging info
	 * @param p packaging
	 */
	void setPackaging(Packaging* p);

	/**
	 * @brief sets shipping info
	 * @param s shipping
	 */
	void setShipping(Shipping* s);

	/**
	 * @brief sets delivery info
	 * @param d delivery
	 */
	void setDelivery(Delivery* d);

	/**
	 * @brief sets payment
	 * @param pay payment
	 */
	void setPayment(Payment* pay);

	/**
	 * @brief gets packaging beggining date
	 * @return date
	 */
	Date& getPackagingBegginingDate() const;

	/**
	 * @brief gets packaging ending date
	 * @return date
	 */
	Date& getPackagingEndDate() const;

	/**
	 * @brief gets shipping beggining date
	 * @return date
	 */
	Date& getShippingBegginingDate() const;

	/**
	 * @brief gets shipping ending date
	 * @return date
	 */
	Date& getShippingEndDate() const;

	/**
	 * @brief gets delivery beggining date
	 * @return date
	 */
	Date& getDeliveryBegginingDate() const;

	/**
	 * @brief gets delivery ending date
	 * @return date
	 */
	Date& getDeliveryEndDate() const;

	/**
	 * @brief confirms/validate payment
	 */
	void validatePayment();

	/**
	 * @brief returns if it is or not a warehousing service
	 */
	virtual bool isWarehousing(){};

	/**
	 * @brief prints a service
	 * @param o ostream
	 * @param s service to be printed
	 * @return ostream
	 */
	friend std::ostream& operator <<(std::ostream& o, const Service& s){
		o << "\n\t\t\t\tSERVICE INFO:\n" << "\t\t\tOrigin: " << s.origin.getCity() << "\t\tDestination: " << s.destination.getCity() <<
				"\n\t\t\tRequested on: " << s.beggining << "\tDelivered on: " << s.end << "\n\n\t\tDETAILED INFO:\n\n\t\t\t" <<
				"Packaging started on: "<< s.getPackagingBegginingDate() << "\tPackaging ended on: " << s.getPackagingEndDate() <<
				"\n\t\t\tShipping started on: " << s.getShippingBegginingDate() << "\tShipping ended on: " << s.getShippingEndDate() <<
				"\n\t\t\tDelivery started on: " << s.getDeliveryBegginingDate() << "\tDelivery ended on " << s.getDeliveryEndDate() <<
				"\n\t\t\tType of Payment: " << s.getPayment()->getPaymentType() << "\t\tPayment status: " << s.getPayment()->getPaymentStatus() <<
			    "\n\t\t\tTotal Price: " << s.getTotalCost();
		return o;
	}
};

/**
 * @brief Class that stores transport service information
 */
class Transport: public Service{
public:
	/**
	 * Transport Constructor
	 */
	Transport(Address& o, Address& d, float w, Date& b, Date& e);

	/**
	 * @return false
	 */
	bool isWarehousing(){ return false; }
};

/**
 * @brief Class that stores warehousing service information
 */
class Warehousing: public Transport{
	int daysWarehouse;
public:
	/**
	 * Warehousing constructor
	 */
	Warehousing(Address& o, Address& d, float w, Date& b, Date& e, int daysWarehouse);

	/*
	 * @brief gets number of days in the warehouse
	 * @return warehouse days
	 */
	int getDaysWarehouse() const;

	/**
	 * @return true
	 */
	bool isWarehousing(){ return true; }
};



#endif /* SERVICE_H_ */
