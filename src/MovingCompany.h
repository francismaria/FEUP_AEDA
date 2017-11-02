/*
 * MovingCompany.h
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef MOVINGCOMPANY_H_
#define MOVINGCOMPANY_H_

#include "Libraries.h"
#include "Client.h"

class MovingCompany{
	std::string name;
	std::string description;
	Date foundingDate;
	std::vector<Client*> clients;
public:
	MovingCompany(std::string n, std::string d, int fd, int fm, int fy);
	std::string getName() const;
	std::string getDescription() const;
	const Date& getFoundingDate() const;
	std::vector<Client*> getClients() const;
	void addClient(Client* c);
};



#endif /* MOVINGCOMPANY_H_ */
