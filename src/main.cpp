//============================================================================
// Name        : main.cpp
// Author      : Francisco Maria / João Gama Amaral
// Version     :
// Copyright   :
// Description : Main file of the first project of AEDA class.
//============================================================================

#include "Libraries.h"
#include "Interface.h"
#include "ImportInfo.h"
#include "ExportInfo.h"


void importInfo(MovingCompany& company, int& numberOfExistentClients){

	importCountries(company);
	importCountriesZones(company);
	importClients(company, numberOfExistentClients);
	importServices(company);

}

void terminateProgram(MovingCompany& company, int numberOfExistentClients){

/*	unsigned int i;

	for(i = 0; i < company.getClients().size(); i++){
		for(unsigned int j = 0; j < company.getClients()[i]->getServicesRequested().size(); j++){
			delete(company.getClients()[i]->getServicesRequested()[j]);
		}
		delete(company.getClients()[i]);
	}*/

	if((int)company.getClients().size() > numberOfExistentClients){
		saveClients(company, (int)company.getClients().size() - numberOfExistentClients);
	}

	company.freeMemory();

	std::cout << "\n\n\t\tProgram terminated." << std::endl;
}

int main() {

	int numberOfExistentClients;

	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", 10, 9, 1995);

	importInfo(company, numberOfExistentClients);

	run(company);

	terminateProgram(company, numberOfExistentClients);

	return 0;
}
