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
#include "Country.h"
#include "Exceptions.h"

/**
 * @brief Class that is the "Mother of all others". It represents a company.
 */
class MovingCompany{
	std::string name;
	std::string description;
	std::string IBAN;
	std::string Entity;
	Date foundingDate;
	std::vector<Client*> clients;
	std::vector<Country*> countriesToOperate;
public:
	/**
	 * Moving Company Constructor
	 */
	MovingCompany(std::string n, std::string d, std::string iban, std::string e, int fd, int fm, int fy);

	/**
	 * @brief gets the company name
	 * @return company name
	 */
	std::string getName() const;

	/**
	 * @brief gets the company's description
	 * @return company description
	 */
	std::string getDescription() const;

	/**
	 * @brief get company founding date
	 * @return founding date
	 */
	const Date& getFoundingDate() const;

	/**
	 * @brief gets all company clients
	 * @return clients
	 */
	std::vector<Client*> getClients() const;

	/**
	 * @brief gets all company's particular clients
	 * @return particular clients
	 */
	std::vector<Client*> getParticularClients() const;

	/**
	 * @brief gets all company's companies clients
	 * @return companies clients
	 */
	std::vector<Client*> getCompaniesClients() const;

	/**
	 * @brief gets countries to which the company operate
	 * @return countries
	 */
	std::vector<Country*> getCountriesToOperate() const;

	/**
	 * @brief gets a specific country searching it by name
	 * @param country name
	 * @return country
	 */
	Country* getCountry(std::string) const;

	/**
	 * @brief adds a new country to operate to the company
	 * @param c country to add to the company
	 */
	void addCountry(Country* c);

	/**
	 * @brief prints all countries to which the company operates
	 */
	void printAllCountriesToOperate() const;

	/**
	 * @briefs given a certain country gets all of the countries to which it operates
	 * @param c country
	 */
	void printCountriesToOperateFrom(Country* c);

	/**
	 * @brief gets the ConnectionCountryInfo object with information of the destination country
	 * @param c country of origin
	 * @param idDestination destination country ID
	 * @return ConnectionCountryInfo object representing the country destination info
	 */
	ConnectionCountryInfo& getCountryDestination(Country* c, int idDestination);


	/**
	 * @brief gets the IBAN of the company
	 * @return company's IBAN
	 */
	std::string getIBAN() const;

	/**
	 * @brief gets the entity representing the company
	 * @return entity of the company
	 */
	std::string getEntity() const;

	/**
	 * @brief adds a new client to the company
	 * @param c new client
	 */
	void addClient(Client* c);

	/**
	 * @brief removes client given a certain ID
	 * @param id ID of the client to be removed
	 */
	void removeClientByID(int id);
	/**
	 * @brief removes client given a certain name
	 * @param name name of the client to be removed
	 */
	void removeClientByName(std::string name);

	/**
	 * @brief removes client given a certain date (joining date)
	 * @param d day of the date
	 * @param m month of the date
	 * @param y year of the date
	 */
	void removeClientByJoiningDate(int d, int m, int y);

	/**
	 * @brief prints client given a certain name using binary search
	 * @param name name of the client to print
	 */
	void printClient(std::string name) const;

	/**
	 * @brief print client given a certain ID
	 * @param id id of the client to print
	 */
	void printClient(int id) const;

	/**
	 * @brief print clients of a vector
	 * @param v clients vector
	 */
	void printByID(std::vector<Client*>& v) const;

	/**
	 * @brief print clients of a vector sorting them by name using bubble sort
	 * @param v clients vector
	 */
	void printByName(std::vector<Client*>& v) const;

	/**
	 * @brief print clients of a vector sorting them by joining date using selection sort
	 * @param v clients vector
	 */
	void printByJoiningDate(std::vector<Client*>& v) const;

	/**
	 * @brief print all clients by ID
	 */
	void printClientsByID() const;

	/**
	 * @brief print all client by name
	 */
	void printClientsByName() const;

	/**
	 * @brief print all clients by joining date
	 */
	void printClientsByJoiningDate() const;

	/**
	 * @brief print all particular clients by ID
	 */
	void printParticularClientsByID() const;

	/**
	 * @brief print all particular clients by name
	 */
	void printParticularClientsByName() const;

	/**
	 * @brief print all particular clients by joining date
	 */
	void printParticularClientsByJoiningDate() const;

	/**
	 * @brief print all company clients by ID
	 */
	void printCompanyClientsByID() const;

	/**
	 * @brief print all company clients by ID
	 */
	void printCompanyClientsByName() const;

	/**
	 * @brief print all company clients by ID
	 */
	void printCompanyClientsByJoiningDate() const;

	/**
	 * @brief prints all services from a client of a given ID
	 * @param id id of the client to print its services
	 */
	void printClientServices(int id) const;

	/**
	 * @brief validates a service of a client given a certain id
	 * @param id id of the client to validate service
	 */
	int validateClientService(int id);

	/**
	 * @brief print client service status (pending/received)
	 * @param id id of the client to check the service
	 */
	int checkClientServiceStatus(int id);

	/**
	 * @brief free all memory alocated by the company
	 */
	void freeMemory();
};



#endif /* MOVINGCOMPANY_H_ */
