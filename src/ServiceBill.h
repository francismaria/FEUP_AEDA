/*
 * ServiceBill.h
 *
 *  Created on: 20/12/2017
 *      Author: Francisco Maria / João Gama Amaral
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
};



#endif /* SERVICEBILL_H_ */
