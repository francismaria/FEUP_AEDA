//============================================================================
// Name        : main.cpp
// Author      : Francisco Maria / Joã Gama Amaral
// Version     :
// Copyright   :
// Description : Main file of the first project of AEDA class.
//============================================================================

#include <iostream>
#include <fstream>

#include "MovingCompany.h"
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

void run(){}

int main() {
	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", 10, 9, 1995);
	Client* c1 = new Client("Francisco Maria", 275254976, "Rua Isabel de Carvalho, n7, 2Direito", "4420-603", 1, 11, 2017);

	company.addClient(c1);
	//Company c();

	//importInfo();

	//run();
	std::cout << *c1;
	//std::cout << company.getClients()[0];

	return 0;
}
