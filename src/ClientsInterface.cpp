/*
 * ClientsInterface.cpp
 *
 *  Created on: 11/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ClientsInterface.h"

int checkClient(MovingCompany& company){
	int option, instruction;

	while(option != -1){

		std::cout << "\tSearch Client:" << std::endl;
		std::cout << "How would you like to search the client?" << std::endl;
		std::cout << "1 - By Name" << std::endl;
		std::cout << "2 - By ID" << std::endl;
		std::cout << "3 - By NIF" << std::endl;
		std::cout << "4 - By Joining Date\n" << std::endl;
		std::cout << "0 - Go Back" << std::endl;
		std::cout << "-1 - Exit Program" << std::endl;

		std::cout << "\nPlease enter an option: ";
		std::cin >> option;

		switch(option){
			case 1:
				instruction = searchClientByName(company);
				break;
			case 2:
				instruction = searchClientByID(company);
				break;
			case 3:
				//instruction = searchClientByNIF(company);
				break;
			case 4:
				//instruction = searchClientByAddress(company);
				break;
			case 5:
				//instruction = searchClientByJoiningDate(company);
				break;
			case 0:
				return 0;
			case -1:
				return -1;
			default:
				std::cout <<"Please insert a valid option.\n" << std::endl;
				break;
			}
		if(instruction == 0) continue;
		if(instruction == -1) return -1;
		}

	return 1;
}

int searchClientByName(MovingCompany& company){

	std::string name;

	std::cout << "0 - Go Back" << std::endl;
	std::cout << "-1 - Exit Program\n" << std::endl;
	std::cout << "Please enter the client's name." <<std::endl;
	std::cout << "Name: " << std::endl;

	std::cin.ignore();
	std::getline(std::cin, name);

	if(name == "0") return 0;
	if(name == "-1") return -1;

	try{
		company.printClient(name);
	}
	catch(NonExistingClient& nc){
		std::cout << "There is no client with the name " << nc.getName();
	}
	return 0;
}

int searchClientByID(MovingCompany& company){

	int id;

	std::cout << "0 - Go Back" << std::endl;
	std::cout << "-1 - Exit Program\n" << std::endl;
	std::cout << "Please enter the client's ID." <<std::endl;
	std::cout << "ID: " << std::endl;

	std::cin >> id;

	if(id == 0) return 0;
	if(id == -1) return -1;

	company.printClient(id);

	return 0;
}

int newParticularClient(MovingCompany& company){

	std::cout << "\n\t\t\t\t\t\t     NEW PARTICULAR CLIENT FORM\n" << std::endl;
	std::cout << "\t\t\t\t\t\t0 - Cancel\t-1 - Exit program\n" << std::endl;

	std::string input;
	std::stringstream ss;

	std::cout <<"\t\t\t\t\tPlease fill out this form in order to add the new client.\n\t\t\t\t\tYou can cancel or exit the "
			"program at any time just enter 0 to cancel or -1 to exit.\n\n"<< std::endl;

	std::cin.ignore();

		//-- NAME
	std::cout << "\t\t\t\tFull Name: ";
	std::getline(std::cin, input);

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string name = input;

	input.clear();

		//-- NIF
	long int nif;
	std::cout << "\n\t\t\t\tNIF: ";
	std::cin >> nif;//input;

	if(nif == -1) return -1;
	else if(nif == 0) return 0;

	input.clear();

		//-- ADDRESS
	std::cout << "\n\t\t\t\tAdress: ";
	std::cin >> input;

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string address = input;

	input.clear();
	std::cin.ignore();

		//-- ZIPCODE
	std::cout << "\n\t\t\t\tZip Code: ";
	std::cin.ignore();
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
	strftime(buffer, sizeof(buffer), "%d %m %y %H %M", timeinfo);

	int day, month, year, hour, minute;
	std::string bufs(buffer);
	std::stringstream aux;

	aux << bufs;

	aux >> day;
	aux >> month;
	aux >> year;
	aux >> hour;
	aux >> minute;

	year += 2000;

	std::cout << day << " " << month << " " << year;

	//ADICIONAR IDADE					AQUI
	Particular* c = new Particular(name, 0, nif, address, zipCode, day, month, year, hour, minute);
	company.addClient(c);

	std::cout << "\n\n\t\t\t\t" << name << " has been added to the company." << std::endl;

	return 0;
}

int newCompanyClient(MovingCompany& company){

	std::cout << "\n\t\t\t\t\t\t     NEW COMPANY CLIENT FORM\n" << std::endl;
	std::cout << "\t\t\t\t\t\t0 - Cancel\t-1 - Exit program\n" << std::endl;

	std::string input;
	std::stringstream ss;

	std::cout <<"\t\t\t\t\tPlease fill out this form in order to add the new client.\n\t\t\t\t\tYou can cancel or exit the "
			"program at any time just enter 0 to cancel or -1 to exit.\n\n"<< std::endl;

	std::cin.ignore();

		//-- COMPANY NAME
	std::cout << "\t\t\t\tCompany Name: ";
	std::getline(std::cin, input);

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string name = input;

		//-- NIF
	long int nif;
	std::cout << "\n\t\t\t\tNIF: ";
	std::cin >> nif;//input;

	if(nif == -1) return -1;
	else if(nif == 0) return 0;

	input.clear();

		//-- ADDRESS
	std::cout << "\n\t\t\t\tAdress: ";
	std::cin >> input;

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string address = input;

	input.clear();
	std::cin.ignore();

		//-- ZIPCODE
	std::cout << "\n\t\t\t\tZip Code: ";
	std::cin.ignore();
	std::getline(std::cin, input);

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string zipCode = input;

	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d %m %y %H %M", timeinfo);

	int day, month, year, hour, minute;
	std::string bufs(buffer);
	std::stringstream aux;

	aux << bufs;

	aux >> day;
	aux >> month;
	aux >> year;
	aux >> hour;
	aux >> minute;

	year += 2000;

	std::cout << day << " " << month << " " << year << " " << hour << " " << minute;

	Company* c = new Company(name, nif, address, zipCode, day, month, year, hour, minute);

	company.addClient(c);

	//std::cout << *company.getCompaniesClients()[0];  -->DEBUG

	std::cout << "\n\n\t\t\t\t" << name << " has been added to the company." << std::endl;

}


int addNewClient(MovingCompany& company){

	int option, instruction;

	while(option != -1){
		std::cout << "\n\n\t\t\t\t\t\t\t      NEW CLIENT FORM\n" << std::endl;
		std::cout << "\t\t\t\t\t\t\t1 - Add new Particular Client" << std::endl;
		std::cout << "\t\t\t\t\t\t\t2 - Add new Company Client\n" << std::endl;
		std::cout << "\t\t\t\t\t\t\t0 - Go back" << std::endl;
		std::cout << "\t\t\t\t\t\t       -1 - Exit Program\n" << std::endl;

		std::cout << "\n\t\t\t\t\tPlease enter an option: ";
		std::cin >> option;

		switch(option){
			case 1:
				instruction = newParticularClient(company);
				if(!instruction) continue;
				break;
			case 2:
				instruction = newCompanyClient(company);
				break;
			case 0:
				return 0;
			case -1:
				return -1;
		}
		if(instruction == 0 || instruction == -1) return instruction;
	}
	return -1;
}

int removeClientByID(MovingCompany& company){

	int enteredID;

	std::cout << "0 - Go Back and Cancel\t\t-1 - Exit Program" << std::endl;
	std::cout << "Please enter the ID of the client you would like to remove:" << std::endl;
	std::cout << "\t-----> ";

	std::cin >> enteredID;

	if(enteredID == 0 || enteredID == -1) return enteredID;

	company.removeClientByID(enteredID);

	std::cout << "\tClient successfully removed." << std::endl;

	return 0;
}


int removeClientByName(MovingCompany& company){

	std::string enteredName;

	std::cout << "0 - Go Back and Cancel\t\t-1 - Exit Program" << std::endl;
	std::cout << "Please enter the name of the client you would like to remove:" << std::endl;
	std::cout << "\t-----> ";


	//ERRRROOOOOOORRRRRRRRRRRRRRRRRRRRRRR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	std::cin.ignore();
	std::getline(std::cin, enteredName);

	// ERRRRRRRRRRRRRRRRRRRRRRRRRRRRROOOOOOOOOOOOOOOOOORRRRRRRRRRRRRRRRRRR!!!!!!!!!!!

	if(enteredName == "0") return 0;
	if(enteredName == "-1") return -1;

	//company.removeClientByName(enteredName);

	std::cout << "\tClient successfully removed." << std::endl;

	return 0;
}

int removeClientByJoiningDate(MovingCompany& company){

	int day, year, month;

	std::cout << "Please enter the joining date of the client you would like to remove:" << std::endl;
	std::cout << "\tDay: ";
	std::cin >> day;

	std::cout << "\tMonth: ";
	std::cin >> month;

	std::cout << "\tYear: ";
	std::cin >> year;

	if(year < company.getFoundingDate().getYear())
		std::cout << "Invalid year." << std::endl;
	else if(month < 1 || month > 12)
		std::cout << "Invalid Month." << std::endl;

	company.removeClientByJoiningDate(day, month, year);

	std::cout << "Client successfully removed.";
}

int removeClient(MovingCompany& company){
	int option, instruction;

	while(option != -1){
		//try{

			std::cout << "\t\t\tRemove Client Form\n" << std::endl;
			std::cout << "\tHow would you like to remove the client?\n" << std::endl;
			std::cout << "\t1 - By ID" << std::endl;
			std::cout << "\t2 - By Name" << std::endl;
			std::cout << "\t3 - By Address" << std::endl;
			std::cout << "\t4 - By Joining Date\n" << std::endl;	//Se aparecerem varios imprimem-se e pergunta-se qual quer remover
			std::cout << "\t0 - Go Back\t\t\t-1 - Exit Program" << std::endl;

			std::cout << "Please insert your option: ";
			std::cin >> option;

			switch(option){
				case 1:
					instruction = removeClientByID(company);		//Binary Search algorithm
					break;
				case 2:
					//instruction = removeClientByName(company);		//Sequential Search algorithm
					break;
				case 3:
					//instruction = removeClientByAddress(company);			//getline error
					break;
				case 4:
					instruction = removeClientByJoiningDate(company);	//Sequential Search algorithm
					break;
				case 0:
					return 0;
				case -1:
					return -1;
					//break;
				default:
					std::cout << "Please insert a valid option.";
					break;
			}
			if(instruction == 0) continue;
			if(instruction == 1) return -1;
		}
		//catch(NonExistingDate& d){
		//	std::cout << "There is no client with that joining date." << std::endl;
			//break;
		//}
	//}
}


int printParticulars(MovingCompany& company){

	int option;

	while(option != -1){

		if(company.getParticularClients().size() == 0){
			std::cout << "There are no particular clients registered." << std::endl;
			break;
		}

		std::cout << "\tPrint Particular Clients" << std::endl;
		std::cout << "How would you like to print the particular clients?\n" << std::endl;
		std::cout << "1 - By ID" << std::endl;
		std::cout << "2 - By Name" << std::endl;
		std::cout << "3 - By joining date\n" << std::endl;
		std::cout << "0 - Go back" << std::endl;
		std::cout << "-1 - Exit program.\n" << std::endl;

		std::cout << "Please insert your option: ";
		std::cin >> option;

		switch(option){
			case 1:
				company.printParticularClientsByID();
				break;
			case 2:
				company.printParticularClientsByName();
				break;
			case 3:
				company.printParticularClientsByJoiningDate();
				break;
			case 0:
				return 0;
			case -1:
				return -1;
			default:
				std::cout << "\nPlease insert a valid option." << std::endl;
				break;
		}
	}

	return 0;

}

int printCompanies(MovingCompany& company){
	int option;

	while(option != -1){

		/*if(company.getCompaniesClients().size() == 0){
			std::cout << "There are no company clients registered." << std::endl;
			break;
		}*/

		std::cout << "\tPrint Company Clients" << std::endl;
		std::cout << "How would you like to print the company clients?\n" << std::endl;
		std::cout << "1 - By ID" << std::endl;
		std::cout << "2 - By Name" << std::endl;
		std::cout << "3 - By joining date\n" << std::endl;
		std::cout << "0 - Go back" << std::endl;
		std::cout << "-1 - Exit program.\n" << std::endl;

		std::cout << "Please insert your option: ";
		std::cin >> option;

		switch(option){
			case 1:
				company.printCompanyClientsByID();
				break;
			case 2:
				company.printCompanyClientsByName();
				break;
			case 3:
				company.printCompanyClientsByJoiningDate();
				break;
			case 0:
				return 0;
			case -1:
				return -1;
			default:
				std::cout << "\nPlease insert a valid option.\n" << std::endl;
				break;
		}
	}

	return 0;
}

int printClients(MovingCompany& company){
	int option;

	while(option != -1){

		if(company.getClients().size() == 0){
			std::cout << "There are no client registered." << std::endl;
			break;
		}

		std::cout << "\tPrint All Clients" << std::endl;
		std::cout << "How would you like to print the clients?\n" << std::endl;
		std::cout << "1 - By ID" << std::endl;
		std::cout << "2 - By Name" << std::endl;
		std::cout << "3 - By joining date\n" << std::endl;
		std::cout << "0 - Go back" << std::endl;
		std::cout << "-1 - Exit program.\n" << std::endl;

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
	}

	return 0;
}


