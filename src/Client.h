/*
 * Client.h
 *
 *  Created on: 31/10/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Libraries.h"
#include "Date.h"
#include "Address.h"
#include "Service.h"

class Client{
	int id;		//o id é sequencial
	long int NIF;
	std::string name;
	Address address;
	Date joiningDate;
	std::vector<Service*> servicesRequested;
	static int numberOfClients;
public:
	Client(){};
	Client(std::string name, long int nif, std::string address, std::string zipCode, int firstDay, int firstMonth, int firstYear);
	int getId() const;
	long int getNIF() const;
	std::string getName() const;
	const Address& getAddress() const;
	std::string getZipCode() const;
	bool operator ==(const Client& c1);
	const Date& getJoiningDate() const;
	std::vector<Service*> getServicesRequested();
	//void addNewService(Transport* t);
	void addNewService(Service* s);
	void printServices() const;
	virtual bool isParticular() {};
	static int getNumberOfClients();
	friend std::ostream& operator<<(std::ostream& o, const Client & c1){
		o << "Client's Info:\n\t" << "Name: " << c1.getName() << "\n\tID: " << c1.getId()
				<< "\n\tRegistered in: " << c1.getJoiningDate() << "\n\t" << c1.getAddress() << "\n" << std::endl;
		return o;
	}
};

class Company: public Client{
	static int numberOfCompanies;
public:
	Company(std::string name, long int nif, std::string address, std::string zipCode, int firstDay, int firstMonth, int firstYear);
	static int getNumberOfCompanies();
	bool isParticular();
};

class Particular: public Client{
	int age;
	static int numberOfParticulars;
public:
	Particular(std::string name, int age, long int nif, std::string address, std::string zipCode, int firstDay, int firstMonth, int firstYear);
	int getAge() const;
	bool isParticular();
	static int getNumberOfParticulars();
};

class NonExistingClient{
public:
	std::string name;
	NonExistingClient(std::string n){ name = n; }
	std::string getName(){ return name; }
};

class NonExistingCompany{
public:
	std::string name;
	NonExistingCompany(std::string n){ name = n; }
	std::string getName(){ return name; }
};

class NonExistingParticular{
public:
	std::string name;
	NonExistingParticular(std::string n){ name = n; }
	std::string getName(){ return name; }
};


#endif /* CLIENT_H_ */
