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


void importInfo(MovingCompany& company, int& numberOfExistentClients, std::vector<int>& clientServices){

	importCountries(company);
	importCountriesZones(company);
	importClients(company, numberOfExistentClients);
	importServices(company);

}

void terminateProgram(MovingCompany& company, int numberOfExistentClients, std::vector<int>& clientServices){

	if((int)company.getClients().size() > numberOfExistentClients){
		saveClients(company, (int)company.getClients().size() - numberOfExistentClients);
	}

	//saveServices();

	company.freeMemory();

	std::cout << "\n\n\t\tProgram terminated." << std::endl;
}

int main() {

	int numberOfExistentClients;
	std::vector<int> clientServices;

	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", "PT50 1452 0023 14698 7456 9878 3", "14579", 10, 9, 1995);

	importInfo(company, numberOfExistentClients, clientServices);

	run(company);

	terminateProgram(company, numberOfExistentClients, clientServices);

	return 0;
}
