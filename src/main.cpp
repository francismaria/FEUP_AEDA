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
#include "Country.h"		//Tem que sair daqui!!!

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

		Particular* c = new Particular(name, age, nif, address, zipCode, 1, 12, 2015);
		company.addClient(c);
	}

	clientsFile.close();

}

void importCountries(MovingCompany& company){

	std::ifstream countriesFile;
	countriesFile.open("InfoFiles/countries.txt");

	if(!countriesFile.good())
		std::cout << "Couldn't access countries.txt file. Error reading from File." << std::endl;

	std::string line;

	while(std::getline(countriesFile, line)){
		Country* c = new Country(line);

		company.addCountry(c);
	}

	countriesFile.close();
}

void importCountriesZones(MovingCompany& company){

	std::ifstream countriesZonesFile;
	countriesZonesFile.open("InfoFiles/countriesZones.txt");

	if(!countriesZonesFile.good())
		std::cout << "Couldn't access countriesZones.txt file. Error reading from File." << std::endl;

	int i = -1;
	unsigned int j;
	std::string line;

	while(std::getline(countriesZonesFile, line)){
		std::stringstream ss(line);
		std::string aux;

		std::getline(ss, aux, ' ');

		if(aux == "C"){
			i++;
		}
		else if(aux == "1"){
			//zone1
			std::string name;
			std::getline(ss, name, '\n');

			for(j = 0; j < company.getCountriesToOperate().size(); j++){
				if(company.getCountriesToOperate()[j]->getName() == name){
					company.getCountriesToOperate()[i]->addZone1Country(company.getCountriesToOperate()[j]);
				}
			}
		}
		else{
			//zone2
			int index;
			std::string name;
			std::getline(ss, name, '\n');

			for(j = 0; j < company.getCountriesToOperate().size(); j++){
				if(company.getCountriesToOperate()[j]->getName() == name){
					company.getCountriesToOperate()[i]->addZone2Country(company.getCountriesToOperate()[j]);
				}
			}

		}
	}
/*
	for(unsigned int k = 0; k < company.getCountriesToOperate().size(); k++){
		for(unsigned int l = 0; l < company.getCountriesToOperate()[k]->getZone2().size(); l++){
			std::cout << company.getCountriesToOperate()[k]->getZone1()[l]->getName() << "ACABOU";
		}
		std::cout << "DONE IT" << std::endl;
	}
*/
	countriesZonesFile.close();
}

void importServices(MovingCompany& company){

}

void importInfo(MovingCompany& company){

	importCountries(company);
	importCountriesZones(company);
	importClients(company);
	importServices(company);

}

void terminateProgram(){
	std::cout << "\n\n\t\tProgram terminated." << std::endl;
}

int main() {

	//int numberofExistentClients;  --> Esta variaável tem o valor de quantos clientes existiam no fich antes da exec do prog de forma a saber quantos novos foram criados e quais sao precisos escrever
	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", 10, 9, 1995);

	importInfo(company);

	run(company);

	terminateProgram();
	//DELETE DE TUDO!!!!!

	return 0;
}
