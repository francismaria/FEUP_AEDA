/*
 * ServicesInterface.cpp
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ServicesInterface.h"

int newRegisteredClientService(MovingCompany& company){

	int idClient;

	std::cout << "\n\n\t\t\t\t\t     REQUEST SERVICE TO REGISTERED CLIENT\n" << std::endl;

	std::cout << "\t\t\t\t    Enter the ID of the client to add a new service: ";
	std::cin >> idClient;

	if(idClient == 0) return 0;
	else if(idClient == -1) return -1;

	std::cout << "\n\n\t\t\t\t    Fill out this form in order to create a new service.\n" << std::endl;
	std::cout << "\t\t\t\t    ORIGIN INFO:\n";

	int weight;
	std::cout << "\n\t\t\t\tEnter the total weight of the volumes (KG): ";
	std::cin >> weight;

	std::cout << "\n\t\t\tSelect from the list of Countries the one where the package will be sent.\n\n";
	company.printAllCountriesToOperate();

	int idOrigin;
	std::cout << "\n\n\t\t\t\tCountry: ";
	std::cin.ignore();
	std::cin >> idOrigin;

	std::cout << "\n\t\t\t\tCity: ";
	std::string city;
	std::cin.ignore();
	std::getline(std::cin, city);

	std::cout << "\n\t\t\t\tStreet Address: ";
	std::string address;
	std::getline(std::cin, address);

	std::cout << "\n\t\t\t\tZip Code: ";
	std::string zipCode;
	std::getline(std::cin, zipCode);

	Address origin(address, zipCode, city, company.getCountriesToOperate()[idOrigin-1]);
	address.clear();
	zipCode.clear();
	city.clear();

	std::cout << "\n\n\t\t\t\t\t     DESTINATION INFO:\n";

	std::cout << "\n\t\t\tSelect from the list of Countries the one where the package will be received.\n\n";
	company.printCountriesToOperateFrom(company.getCountriesToOperate()[idOrigin-1]);

	int idDestination;
	std::cout << "\n\n\t\t\t\tCountry: ";
	std::cin >> idDestination;

	std::cout << "\n\t\t\t\tCity: ";
	std::cin.ignore();
	std::getline(std::cin, city);

	std::cout << "\n\t\t\t\tStreet Address: ";
	std::getline(std::cin, address);

	std::cout << "\n\t\t\t\tZip Code: ";
	std::getline(std::cin, zipCode);

	int zone = 0;

	Address destination(address, zipCode, city, company.getCountryDestination(company.getCountriesToOperate()[idOrigin-1], idDestination));

	std::cout << company.getCountryDestination(company.getCountriesToOperate()[idOrigin-1], idDestination).getName();

	int day, month, year;
	std::cout << "\n\n\t\t\t\t\t\tDATE INFO:" << std::endl;
	std::cout << "\n\n\t\t\t\tDay: ";
	std::cin >> day;
	std::cout << "\n\n\t\t\t\tMonth: ";
	std::cin >> month;
	std::cout << "\n\n\t\t\t\tYear: ";
	std::cin >> year;

	Date dB(day,month,year);

	//Transport* t = new Transport(origin, destination, weight);

	//std::cout << t->getOrigin();

	//company.getClients()[idClient-1]->addNewService(t);

	std::cout << company.getClients()[idClient-1]->getServicesRequested().size();

	return 0;
}

int newUnregisteredClientService(MovingCompany& company){

	return 0;
}

int newService(MovingCompany& company){

	int option;

	std::cout << "\n\n\t\t\t\t\t\t\tREQUEST NEW SERVICE FORM\n" << std::endl;
	std::cout << "\t\t\tPlease enter if you want to request a service to an already REGISTERED client or to an UNREGISTERED client." << std::endl;
	std::cout << "\n\t\t\t\t\t\t\t1 - Registered Client" << std::endl;
	std::cout << "\t\t\t\t\t\t\t2 - Unregistered Client\n" << std::endl;
	std::cout << "\t\t\t\t\t\t\t0 - Go back" << std::endl;
	std::cout << "\t\t\t\t\t\t       -1 - Exit Program\n" << std::endl;

	std::cout << "\n\t\t\t\t\tPlease enter an option: ";
	std::cin >> option;

	while(option != -1){
		int instruction;

		switch(option){
			case 1:
				instruction = newRegisteredClientService(company);
				break;
			case 2:
				instruction = newUnregisteredClientService(company);
				break;
			case 0:
				return 0;
			case -1:
				return -1;
		}
		if(!instruction) continue;
		if(instruction == -1) return -1;
	}
	return -1;
}

int printClientsServices(MovingCompany& company){
	/*
	int option;

	std::cout << "\n\n\t\t\t\t\t\t\tPRINT CLIENT SERVICES\n" << std::endl;
	std::cout << "Enter the ID of the client to check the services: ";

	std::cin >> option;

	while(option != -1){
		int instruction;

		switch(option){
			case 1
		}
	}

	return -1;*/
	int id;

	std::cout << "\n\n\t\t\t\t\t\t\tPRINT CLIENT SERVICES\n" << std::endl;
	std::cout << "Enter the ID of the client to check the services: ";

	std::cin >> id;

	company.printClientServices(id);
}



