/*
 * ServiceBill.h
 *
 *  Created on: 20/12/2017
 *      Author: Francisco Maria / Jo�o Gama Amaral
 */

#ifndef SERVICEBILL_H_
#define SERVICEBILL_H_

#include "Client.h"

/**
 * @brief Class that represents a bill of a given service
 */
class ServiceBill{
	Client* client;
	Service* service;
public:

	/**
	 * @brief ServiceBill default constructor
	 */
	ServiceBill();

	/**
	 * @brief ServiceBill constructor
	 */
	ServiceBill(Client* c, Service* s);

	/**
	 * @brief Gets client
	 * @return client
	 */
	Client* getClient() const;

	/**
	 * @brief Gets serviceID
	 * @return ID
	 */
	Service* getService() const;

	/**
	 * @brief Checks which the two of the ServiceBill objects is the "lesser"
	 * @return true or false
	 */
	bool operator <(const ServiceBill& sb) const;

	/**
	 * @brief Checks if two ServiceBill objects are the same
	 * @return true or false
	 */
	bool operator ==(const ServiceBill& sb) const;

	/**
	 * @brief Operator to print ServiceBill object
	 * @param o ostream
	 * @param sb const ServiceBill&
	 * @return ostream object
	 */
	friend std::ostream& operator <<(std::ostream& o, const ServiceBill& sb){
		o << "\n\t\t\t\t\t\tSERVICE BILL" << "\n\t\t\t\tName: " << sb.getClient()->getName() <<
				"\n\t\t\t\tNIF: " << sb.getClient()->getNIF() << "\n\t\t\t\tDate: " << sb.getService()->getBeggining() <<
				"\n\t\t\t\t\tServices: " << "\n\t\t\t\tPackaging: " << sb.getService()->getPackagingCost() <<
				"\n\t\t\t\tShipping: " << sb.getService()->getShippingCost() << "\n\t\t\t\tDelivery: " <<
				sb.getService()->getDeliveryCost() << "\n\n\t\t\t\tTotal Cost: " << sb.getService()->getTotalCost() << std::endl;
		return o;
	}
};



#endif /* SERVICEBILL_H_ */
