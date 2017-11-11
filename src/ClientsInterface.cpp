/*
 * ClientsInterface.cpp
 *
 *  Created on: 11/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ClientsInterface.h"

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
	return true;
}

int newParticularClient(MovingCompany& company){

	std::cout << "\t\t\t NEW PARTICULAR\n" << std::endl;
	std::cout << "\t0 - Cancel\t-1 - Exit program\n" << std::endl;

	std::string input;
	std::stringstream ss;

	std::cout <<"\tPlease fill out this form in order to add the new client."<< std::endl;

	std::cin.ignore();

		//-- NAME
	std::cout << "\tName: ";
	std::getline(std::cin, input);

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string name = input;

	input.clear();

		//-- NIF
	long int nif;
	std::cout << "\n\tNIF: ";
	std::cin >> nif;//input;

	if(nif == -1) return -1;
	else if(nif == 0) return 0;

	input.clear();

		//-- ADDRESS
	std::cout << "\n\tAdress: ";
	std::cin >> input;

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string address = input;

	input.clear();
	std::cin.ignore();

		//-- ZIPCODE
	std::cout << "\n\tZip Code: ";
	std::getline(std::cin, input);

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string zipCode = input;

		//-- DATE
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d %m %y", timeinfo);

	int day, month, year;
	std::string bufs(buffer);
	std::stringstream aux;

	aux << bufs;

	aux >> day;
	aux >> month;
	aux >> year;

	year += 2000;

	std::cout << day << " " << month << " " << year;

	Client* c = new Client(name, nif, address, zipCode, day, month, year);		//tem que ser uma data real!!!
	company.addClient(c);

	std::cout << "\n\n\t" << name << " has been added to the company." << std::endl;

	return 0;

}


int addNewClient(MovingCompany& company){

	int option, instruction;

	while(option != -1){
		std::cout << "\t\tNew Client Form\n" << std::endl;
		std::cout << "\t1 - Add new Particular Client" << std::endl;
		std::cout << "\t2 - Add new Company Client" << std::endl;
		std::cout << "0 - Go back\t\t\t\t-1 - Exit Program\n" << std::endl;

		std::cout << "Please insert your option: ";
		std::cin >> option;

		switch(option){
			case 1:
				instruction = newParticularClient(company);
				break;
			case 2:
				//instruction = newCompanyClient(company);
				break;
			case 0:
				return 0;
			case -1:
				break;
				//return -1;
		}
		if(instruction == 0 || instruction == -1) return instruction;
	}
	return -1;
}


int printClients(MovingCompany& company){
	int option;

	std::cout << "\tPrint All Clients" << std::endl;
	std::cout << "How would you like to print the clients?\n" << std::endl;
	std::cout << "1 - By ID" << std::endl;
	std::cout << "2 - By Name" << std::endl;
	std::cout << "3 - By joining date\n" << std::endl;
	std::cout << "0 - Go back" << std::endl;
	std::cout << "-1 - Exit program.\n" << std::endl;

	while(option != -1){
		int instruction = 1;

		std::cout << "Please insert your option: ";
		std::cin >> option;

		switch (option){
			case 1:
				company.printClientsByID();
				break;
			case 2:								//This function prints clients by name using BUBBLE SORT!
				company.printClientsByName();
				break;
			case 3:								//This function prints clients by joining date using SELECTION SORT!
				company.printClientsByJoiningDate();
				break;
			case 0:
				return 0;
			case -1:
				return 1;
			default:
				std::cout << "Please insert a valid option.\n" << std::endl;
				break;
		}

		if(instruction == 0 || instruction == -1) return instruction;

	}
}


