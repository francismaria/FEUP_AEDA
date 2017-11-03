/*
 * Interface.cpp
 *
 *  Created on: 02/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "Interface.h"

void run(MovingCompany& company){
	bool exit = false;

	std::cout << "\t\t\t\tWelcome to this Software.\n" << std::endl;

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

	std::cout << "\t\t\t\t\t\tMENU\n" << std::endl;
	std::cout << "\t\t\t1 - Clients" << std::endl;
	std::cout << "\t\t\t2 - Services" << std::endl;
	std::cout << "\n\t\t\t-1 - Exit Program" << std::endl;
	std::cout << "\t\t\nPlease enter an option: ";

	std::cin >> option;
	return option;
}

bool showClientsMenu(MovingCompany& company){
	int option;

	std::cout <<"\tClients:\n" << std::endl;
	std::cout << "1 - Check client" << std::endl;
	std::cout << "2 - Add client" << std::endl;
	std::cout << "3 - Remove client" << std::endl;
	std::cout << "0 - Go back" << std::endl;
	std::cout << "-1 - Exit program.\n" << std::endl;

	while(option != -1){
		int instruction;

		std::cout << "\nPlease insert your option: ";
		std::cin >> option;

		switch(option){
			case 1:
				instruction = checkClient(company);
				break;
			case 2:
				//instruction = addNewClient(company);
				break;
			case 3:
				//instruction = removeClient(company);
				break;
			case 0:
				instruction = 0;
				break;
			case -1:
				instruction = -1;
				break;
			default:
				std::cout << "Please insert a valid option.";
				break;
		}

		if(instruction == -1) return true;
		else if(instruction == 0) return false;
	}
	return false;
}

bool checkClient(MovingCompany& company){
	int option;

	std::cout << "\tSearch Client:" << std::endl;
	std::cout << "How would you like to search the client?" << std::endl;
	std::cout << "1 - Name1\n" << "2 - ID\n" << "3 - NIF\n" << "4 - Address" << "5 - First registration date\n" << std::endl;
	std::cout << "\nOption: ";

	std::cin >> option;
	/*
	while(instruction != -1)
	switch(option){
		case 1:
			searchClientName();
			break;
		case 2:
			searchClientID();
			break;
		case 3:
			searchClientNIF();
			break;
		case 4:
			searchClientAddress();
			break;
		case 5:
			searchClientDate();
			break;
		default:
			//Please insert a valid option  ---> std::cout <<"Please insert a valid option.";
			break;
		}
	*/
}


bool showServicesMenu(MovingCompany& company){
	std::cout << "SERVICES MENU\n";
	return true;
}



