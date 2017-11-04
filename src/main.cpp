//============================================================================
// Name        : main.cpp
// Author      : Francisco Maria / João Gama Amaral
// Version     :
// Copyright   :
// Description : Main file of the first project of AEDA class.
//============================================================================

#include "Libraries.h"
#include <fstream>

#include "Interface.h"

void importClients(MovingCompany& company){
	std::ifstream clientsFile;
	clientsFile.open("InfoFiles/clients.txt");

	if(!clientsFile.good())
		std::cout << "Couldn't access clients.txt file. Error reading from File." << std::endl;

	int fDay, fMonth, fYear, age;
	long int nif;
	std::string name, zipCode, address, line, city, country;

	while(std::getline(clientsFile, line)){

		std::stringstream ss(line);
		std::string aux;
		std::stringstream auxSS;

		// Name
		std::getline(ss, name, '/');

		// Age
		std::getline(ss, aux, '/');
		auxSS << aux;
		auxSS >> age;

		aux.clear();
		auxSS.str(std::string());

		// NIF
		std::getline(ss, aux, '/');
		auxSS << aux;
		auxSS >> nif;

		aux.clear();
		auxSS.str(std::string());

		// Address
		std::getline(ss, address, '/');

		// Zip Code
		std::getline(ss, zipCode, '/');

		// City
		std::getline(ss, city, '/');

		// Country
		std::getline(ss, country, '/');
/*
		// Data
		std::getline(ss, aux, '/');
		auxSS << aux;				//Day
		auxSS >> fDay;

		aux.clear();
		auxSS.str(std::string());

		std::getline(ss, aux, '/');
		auxSS << aux;				//Month
		auxSS >> fMonth;

		aux.clear();
		auxSS.str(std::string());


		std::getline(ss, aux, '/');
		auxSS << aux;				//Year
		auxSS >> fYear;

		aux.clear();
		auxSS.str(std::string());*/

		Client* c = new Particular(name, age, nif, address, zipCode, 1, 12, 2015);
		company.addClient(c);
	}

	clientsFile.close();

}

void importInfo(MovingCompany& company){
	//importCountries();
	importClients(company);
	//import
}

void terminateProgram(){
	std::cout << "\n\n\t\tProgram terminated." << std::endl;
}

int main() {
	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", 10, 9, 1995);

	importInfo(company);

	run(company);

	terminateProgram();

	return 0;
}
