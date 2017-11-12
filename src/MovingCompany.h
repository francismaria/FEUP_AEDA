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
	std::vector<Client*> getParticularClients() const;
	std::vector<Client*> getCompaniesClients() const;
	void addClient(Client* c);
	void removeClientByID(int id);
	void removeClientByName(std::string name);
	void removeClientByAddress(std::string address);
	void removeClientByJoiningDate(int d, int m, int y);
	void printClient(std::string name) const;
	void printClient(int id) const;
	void printClient(long int nif) const;
	void printClient() const;
	void printByID(std::vector<Client*>& v) const;
	void printByName(std::vector<Client*>& v) const;
	void printByJoiningDate(std::vector<Client*>& v) const;
	void printClientsByID() const;
	void printClientsByName() const;
	void printClientsByJoiningDate() const;
	void printParticularClientsByID() const;
	void printParticularClientsByName() const;
	void printParticularClientsByJoiningDate() const;
	void printCompanyClientsByID() const;
	void printCompanyClientsByName() const;
	void printCompanyClientsByJoiningDate() const;
};



#endif /* MOVINGCOMPANY_H_ */
