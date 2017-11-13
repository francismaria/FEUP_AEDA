/*
 * ServicesInterface.cpp
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ServicesInterface.h"

int newRegisteredClientService(MovingCompany& company){

	int id;

	std::cout << "\n\n\t\t\t\t\t     REQUEST SERVICE TO REGISTERED CLIENT\n" << std::endl;

	std::cout << "\t\t\t\t    Enter the ID of the client to add a new service: ";
	std::cin >> id;

	std::cout << "\n\n\t\t\t\t    Fill out this form in order to create a new service.\n" << std::endl;
	std::cout << "\t\t\t\t    ORIGIN INFO:\n";

	//LIST COUNTRIES!!!!
	std::cout << "\n\t\t\tSelect from the list of Countries the one where the package will be sent.\n\n";
	company.printAllCountriesToOperate();

	std::cout << "\n\n\t\t\t\tCountry: ";
	std::string country;
	std::cin.ignore();
	std::getline(std::cin, country);

	std::cout << "\n\n\t\t\t\tCity: ";
	std::string city;
	std::getline(std::cin, city);

	std::cout << "\n\n\t\t\t\tStreet Address: ";
	std::string address;
	std::getline(std::cin, address);

	std::cout << "\n\n\t\t\t\tZip Code: ";
	std::string zipCode;
	std::getline(std::cin, zipCode);

	Address origin(address, zipCode, city, country);
	address.clear();
	zipCode.clear();
	city.clear();
	country.clear();

	std::cout << "\n\n\t\t\t\tDESTINATION INFO:\n";

	std::cout << "\n\n\t\t\t\tCountry: ";
	std::getline(std::cin, country);

	std::cout << "\n\n\t\t\t\tCity: ";
	std::getline(std::cin, city);

	std::cout << "\n\n\t\t\t\tStreet Address: ";
	std::getline(std::cin, address);

	std::cout << "\n\n\t\t\t\tZip Code: ";
	std::getline(std::cin, zipCode);

	Address destination(address, zipCode, city, country);

	int day, month, year;
	std::cout << "\n\n\t\t\t\tDATE INFO:" << std::endl;
	std::cout << "\n\n\t\t\t\tDay: ";
	std::cin >> day;
	std::cout << "\n\n\t\t\t\tMonth: ";
	std::cin >> month;
	std::cout << "\n\n\t\t\t\tYear: ";
	std::cin >> year;

	Date dB(day,month,year);

	Packaging* p = new Packaging(dB);
	Shipping* s = new Shipping(origin, destination);

	Transport* t = new Transport(p, s);

	std::cout << t->getPackingBeggining();

	company.getClients()[id-1]->addNewService(t);

	std::cout << company.getClients()[id-1]->getServicesRequested().size();
}

int newUnregisteredClientService(MovingCompany& company){

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




