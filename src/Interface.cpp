/*
 * Interface.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Interface.h"

void run(MovingCompany& company){
	bool exit = false;

	std::cout << "\t\t\tWelcome to this Software.\n" << std::endl;

	while(!exit){
		int option = showMenu(company);

		switch(option){
		case 1:
			exit = showClientsMenu(company);
			break;
		case 2:
			exit = showServicesMenu(company);
			break;
		default:
			break;
		}

		std::cout << option;
		//exit = true;

	}
}

int showMenu(MovingCompany& company){
	int option;

	std::cout << "\tMenu:\n" << std::endl;
	std::cout << "1 - Clients" << std::endl;
	std::cout << "2 - Services" << std::endl;
	std::cout << "Please enter an option: " << std::endl;

	std::cin >> option;
	return option;
}

bool showClientsMenu(MovingCompany& company){
	std::cout << "CLIENTS MENU" << *company.getClients()[0];
	return true;
}

bool showServicesMenu(MovingCompany& company){
	std::cout << "SERVICES MENU\n";
	return true;
}



