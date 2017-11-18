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
	int id;
	long int NIF;
	std::string name;
	Address address;
	Date joiningDate;
	std::vector<Service*> servicesRequested;
	static int numberOfClients;
public:
	Client(){};
	~Client(){};		//ADDED
	Client(std::string name, long int nif, std::string address, std::string zipCode, int firstDay, int firstMonth, int firstYear);
	Client(std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);
	int getId() const;
	long int getNIF() const;
	std::string getName() const;
	const Address& getAddress() const;
	std::string getZipCode() const;
	bool operator ==(const Client& c1);
	const Date& getJoiningDate() const;
	std::vector<Service*> getServicesRequested();
	void addNewService(Service* s);
	void printServices() const;
	virtual bool isParticular() {};
	virtual int getAge() {}
	static int getNumberOfClients();
	friend std::ostream& operator<<(std::ostream& o, const Client & c1){
		o << "Client's Info:\n\t" << "Name: " << c1.getName() << "\n\tID: " << c1.getId()
				<< "\n\tRegistered in: " << c1.getJoiningDate() << "\n\t" << c1.getAddress() << "\n" << std::endl;
		return o;
	}
};

class Company: public Client{		//acrescentar o custo Mensal
	static int numberOfCompanies;
public:
	Company(std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);
	static int getNumberOfCompanies();
	bool isParticular();
};

class Particular: public Client{
	int age;
	static int numberOfParticulars;
public:
	Particular(std::string name, int age, long int nif, std::string address, std::string zipCode, int firstDay, int firstMonth, int firstYear);
	Particular(std::string name, int age, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);
	int getAge();
	bool isParticular();

	static int getNumberOfParticulars();
};

#endif /* CLIENT_H_ */
