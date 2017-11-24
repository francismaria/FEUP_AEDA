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

/**
 * 	@brief Class that stores all of the client related information.
 */
class Client{
	int id;
	long int NIF;
	std::string name;
	Address address;
	Date joiningDate;
	std::vector<Service*> servicesRequested;
	static int numberOfClients;
public:
	/**
	 * Default Constructor
	 */
	Client(){};

	/**
	 * Default Destructor
	 */
	~Client(){};

	/**
	 * Constructor to new Client
	 */
	Client(std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);

	/**
	 * Client constructor w/ ID (already existing clients)
	 */
	Client(int ID, std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);

	/**
	 * @brief gets client ID
	 * @return ID number
	 */
	int getId() const;

	/**
	 * @brief gets client NIF
	 * @return NIF number
	 */
	long int getNIF() const;

	/**
	 * @brief gets client name
	 * @return string with name
	 */
	std::string getName() const;

	/**
	 * @brief gets client address
	 * @return address
	 */
	const Address& getAddress() const;

	std::string getZipCode() const;

	/**
	 * @brief checks if clients are equal
	 * @param c1 another client
	 * @return true or false
	 */
	bool operator ==(const Client& c1);

	/**
	 * @brief gets clients joining date to the company
	 * @return joining date
	 */
	const Date& getJoiningDate() const;

	/**
	 * @brief gets all clients services requested
	 * @return vector of services requested by the client
	 */
	std::vector<Service*> getServicesRequested();

	/**
	 * @brief adds new service to the clients service requested
	 * @param s service pointer
	 */
	void addNewService(Service* s);

	/**
	 * @brief prints all services requested by the client
	 */
	void printServices() const;

	/**
	 * @brief prints the status of the clients service passed as parameter by ID
	 * @param sID service ID to check service status
	 */
	void checkServiceStatus(int sID) const;

	/**
	 * @brief validates client service
	 * @param sID represents the service ID to validate its payment
	 */
	void validatePayment(int sID);

	/**
	 * @brief deletes all of the services associated w/ the client
	 */
	void deleteServices();

	/**
	 * @brief checks if a client is particular
	 * @return true or false if is or not a particular client
	 */
	virtual bool isParticular() {};

	/**
	 * @brief gets client age if particular
	 * @return client's age
	 */
	virtual int getAge() {}

	/**
	 * @brief gets the total amount of clients registered in the company
	 * @return total amount
	 */
	static int getNumberOfClients();

	/**
	 * @brief Prints a client
	 * @param o ostream
	 * @param c1 client
	 * @return ostream
	 */
	friend std::ostream& operator<<(std::ostream& o, const Client & c1){
		o << "Client's Info:\n\t" << "Name: " << c1.getName() << "\n\tID: " << c1.getId()
				<< "\n\tRegistered in: " << c1.getJoiningDate() << "\n\t" << c1.getAddress() << "\n" << std::endl;
		return o;
	}
};

/**
 * 	@brief Class that represents a company client.
 */
class Company: public Client{
	static int numberOfCompanies;
public:
	/**
	 * Constructor to the Company client
	 */
	Company(std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);


	Company(int id, std::string name, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);
	/**
	 * @brief gets the total amount of company clients registered in the company
	 * @return total amount of companies
	 */
	static int getNumberOfCompanies();

	/**
	 * @return false
	 */
	bool isParticular();
};

/**
 * 	@brief Class that represents a particular client.
 */
class Particular: public Client{
	int age;
	static int numberOfParticulars;
public:
	/**
	 * Constructor to Particular Client
	 */
	Particular(std::string name, int age, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);

	Particular(int id, std::string name, int age, long int nif, std::string address, std::string zipCode, std::string city, std::string country, int firstDay, int firstMonth, int firstYear, int hour, int minute);
	/**
	 * @brief gets particular client age
	 * @return age
	 */
	int getAge();

	/**
	 * @return true;
	 */
	bool isParticular();

	/**
	 * @return amount of particular clients
	 */
	static int getNumberOfParticulars();
};

#endif /* CLIENT_H_ */
