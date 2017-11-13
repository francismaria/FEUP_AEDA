/*
 * Interface.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / Jo�o Gama Amaral
 */

#include "Interface.h"

void run(MovingCompany& company){
	bool exit = false;

	std::cout << "\t\t\t\t\t\t\tWelcome to this Software.\n" << std::endl;

	while(!exit){
		int option = showMenu(company);

		switch(option){
			case 1:
				exit = showClientsMenu(company);
				break;
			case 2:
				exit = showServicesMenu(company);
				break;
			case -1:
				exit = true;
				break;
			default:
				std::cout << "Please insert a valid option.\n";
				break;
		}

		if(exit) break;
	}
}

int showMenu(MovingCompany& company){
	int option;

	std::cout << "\t\t\t\t\t\t\t\tMENU\n" << std::endl;
	std::cout << "\t\t\t\t\t\t\t1 - Clients" << std::endl;
	std::cout << "\t\t\t\t\t\t\t2 - Services" << std::endl;
	std::cout << "\n\t\t\t\t\t\t       -1 - Exit Program\n\n" << std::endl;
	std::cout << "\n\t\t\t\t\tPlease enter an option: ";

	std::cin >> option;
	return option;
}

bool showClientsMenu(MovingCompany& company){
	int option;

	std::cout <<"\n\n\t\t\t\t\t\t\t\tCLIENTS\n" << std::endl;
	std::cout << "\t\t\t\t\t\t\t1 - Check client" << std::endl;
	std::cout << "\t\t\t\t\t\t\t2 - Add client" << std::endl;
	std::cout << "\t\t\t\t\t\t\t3 - Remove client" << std::endl;
	std::cout << "\t\t\t\t\t\t\t4 - Print particular clients" << std::endl;
	std::cout << "\t\t\t\t\t\t\t5 - Print company clients" << std::endl;
	std::cout << "\t\t\t\t\t\t\t6 - Print all clients" << std::endl;
	//std::cout << "\t\t\t\t\t\t\t7 - Update Client's Info\n" << std::endl;
	std::cout << "\t\t\t\t\t\t\t0 - Go back" << std::endl;
	std::cout << "\t\t\t\t\t\t       -1 - Exit program.\n" << std::endl;

	while(option != -1){
		int instruction;

		std::cout << "\n\t\t\t\t\tPlease enter an option: ";
		std::cin >> option;

		switch(option){
			case 1:
				instruction = checkClient(company);			//To be done
				break;
			case 2:
				instruction = addNewClient(company);		// To be done company
				break;
			case 3:
				instruction = removeClient(company);
				break;
			case 4:
				instruction = printParticulars(company);
				break;
			case 5:
				instruction = printCompanies(company);
				break;
			case 6:
				instruction = printClients(company);		//DONE!!
				//if(printClients(company)){
					//continue;  //GO BACK da fun��o
				break;
			case 0:
				//instruction = 0;
				return false;
				//break;
			case -1:
				instruction = -1;
				break;
			default:
				std::cout << "Please insert a valid option.";
				break;
		}

		if(instruction == -1) return true;
		else if(instruction == 0) continue;//return false;
	}
	return false;
}


bool showServicesMenu(MovingCompany& company){
	int option;

	std::cout << "\n\n\t\t\t\t\t\t\t\tSERVICES\n" << std::endl;
	std::cout << "\t\t\t\t\t\t\t1 - Request New Service" << std::endl;
	std::cout << "\t\t\t\t\t\t\t2 - Check Service Status" << std::endl;
	std::cout << "\t\t\t\t\t\t\t3 - Print Client's Services History\n" << std::endl;
	std::cout << "\t\t\t\t\t\t\t0 - Go back" << std::endl;
	std::cout << "\t\t\t\t\t\t       -1 - Exit program.\n" << std::endl;

	while(option != -1){
		int instruction;

		std::cout << "\n\t\t\t\t\tPlease enter an option: ";
		std::cin >> option;

		switch(option){
			case 1:
				instruction = newService(company);
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
				return false;
			case -1:
				return true;
		}

		if(instruction == 0) continue;
		if(instruction == -1) return true;
	}

	return true;
}













///---------------------------------------------
/*
void testServices(MovingCompany& company){
	int id;
	std::cout << "REQUEST SERVICE" << std::endl;

	std::cout << "1 - Registered Client\n" << std::endl;
	//std::cout << "2 - "
	std::cout << "Enter the ID of the client you would like to add a new service:";
	//Pode ser um cliente n�o registado!!!!
	std::cin >> id;

	std::cout << "PLEASE FILL OUT THIS FORM IN ORDER TO CREATE SERVICE.\n";
	std::cout << "Please enter the origin.\n";

	std::cout << "Country: ";
	std::string country;
	std::cin.ignore();
	std::getline(std::cin, country);

	std::cout << "City: ";
	std::string city;
	std::getline(std::cin, city);

	std::cout << "Street Address: ";
	std::string address;
	std::getline(std::cin, address);

	std::cout << "Zip Code: ";
	std::string zipCode;
	std::getline(std::cin, zipCode);

	Address origin(address, zipCode, city, country);
	address.clear();
	zipCode.clear();
	city.clear();
	country.clear();

	std::cout << "Please enter the Destination.\n";

	std::cout << "Country: ";
	std::getline(std::cin, country);

	std::cout << "City: ";
	std::getline(std::cin, city);

	std::cout << "Street Address: ";
	std::getline(std::cin, address);

	std::cout << "Zip Code: ";
	std::getline(std::cin, zipCode);

	Address destination(address, zipCode, city, country);

	int day, month, year;
	std::cout << "Please enter the date you would like to send the package: ";
	std::cout << "Day: ";
	std::cin >> day;
	std::cout << "Month: ";
	std::cin >> month;
	std::cout << "Year: ";
	std::cin >> year;

	Date dB(day,month,year);

	Packaging* p = new Packaging(dB);
	Shipping* s = new Shipping(origin, destination);

	Transport* t = new Transport(p, s);

	std::cout << t->getPackingBeggining();

	company.getClients()[id-1]->addNewService(t);

	std::cout << company.getClients()[id-1]->getServicesRequested().size();


}*/

