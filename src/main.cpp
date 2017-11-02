//============================================================================
// Name        : main.cpp
// Author      : Francisco Maria / Joã Gama Amaral
// Version     :
// Copyright   :
// Description : Main file of the first project of AEDA class.
//============================================================================

#include <iostream>
#include <fstream>

#include "Interface.h"
//Include Interface [{while user !pressed exit... }

void importClients(){
	std::ifstream clientsFile;
	clientsFile.open("../InfoFiles/clients.txt");

}

void importInfo(){
	//importCountries();
	importClients();
	//import
}

int main() {
	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", 10, 9, 1995);

	Company* c1 = new Company("Eletrodomesticos Flavienses", 154654896, "Parque Industrial de Chaves, lote 75, II", "4400-589", 25,5,2016);
	company.addClient(c1);

	importInfo();

	run(company);

	return 0;
}
