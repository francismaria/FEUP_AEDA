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
//Include Interface [{while user !pressed exit... }

void importClients(){
	std::ifstream clientsFile;
	clientsFile.open("../InfoFiles/clients.txt");

	int fDay, fMonth, fYear, age;
	long int NIF;
	std::string name, zipCode, address, line;

	while(std::getline(clientsFile, line)){
		std::string::size_type i = 0;

		i = line.find("/");
		name = line.substr(0, i);
		line = line.substr(i + 1);

		i = line.find("/");
		age = std::stoi(line.substr(0, i));
		line = line.substr(i + 1);



	}

}

void importInfo(){
	//importCountries();
	importClients();
	//import
}

void terminateProgram(){
	std::cout << "\n\n\t\tProgram terminated." << std::endl;
}

int main() {
	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", 10, 9, 1995);

	Company* c1 = new Company("Eletrodomesticos Flavienses", 154654896, "Parque Industrial de Chaves, lote 75, II", "4400-589", 25,5,2016);
	company.addClient(c1);

	//importInfo();

	//run(company);

	terminateProgram();

	return 0;
}
