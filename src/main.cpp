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

	saveClients(company);

	saveServices(company);

	company.freeMemory();

	std::cout << "\n\n\t\tProgram terminated." << std::endl;
}

int main() {

	int numberOfExistentClients;

	MovingCompany company("EletroMoving, S.A.", "Great company with moving.", "PT50 1452 0023 14698 7456 9878 3", "14579", 10, 9, 1995);

	importInfo(company, numberOfExistentClients);

	run(company);

	terminateProgram(company, numberOfExistentClients);

	return 0;
}
