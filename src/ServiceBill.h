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
	int serviceID;
public:
	/**
	 * @brief ServiceBill constructor
	 */
	ServiceBill(Client* c, int sID);

	/**
	 * @brief Gets client
	 * @return client
	 */
	Client* getClient();

	/**
	 * @brief Gets serviceID
	 * @return ID
	 */
	int getServiceID() const;

	/**
	 * @brief Checks which the two of the ServiceBill objects is the "lesser"
	 * @return true or false
	 */
	bool operator <(const ServiceBill& sb);

	/**
	 * @brief Checks if two ServiceBill objects are the same
	 * @return true or false
	 */
	bool operator ==(const ServiceBill& sb);
};



#endif /* SERVICEBILL_H_ */
