/*
 * ServicesInterface.cpp
 *
 *  Created on: 12/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ServicesInterface.h"

int newRegisteredClientService(MovingCompany& company){

	int idClient;

	std::cout << "\n\n\t\t\t\t\t     REQUEST SERVICE TO REGISTERED CLIENT\n" << std::endl;

	//se calhar é melhor meter uma lista com os nomes dos clientes e seus ID's(assim porde escolher)

	std::cout << "\t\t\t\t    Enter the ID of the client to add a new service: ";
	std::cin >> idClient;

	if(idClient == 0) return 0;
	else if(idClient == -1) return -1;

	std::cout << "\n\n\t\t\t\t    Fill out this form in order to create a new service.\n" << std::endl;
	std::cout << "\t\t\t\t    ORIGIN INFO:\n";

	int weight;
	std::cout << "\n\t\t\t\tEnter the total weight of the volumes (KG): ";
	std::cin >> weight;

	if(weight == 0) return 0;
	else if(weight == -1) return -1;

	std::cout << "\n\t\t\tSelect from the list of Countries the one where the package will be sent.\n\n";
	company.printAllCountriesToOperate();

	int idOrigin;
	std::cout << "\n\n\t\t\t\tCountry: ";
	std::cin.ignore();
	std::cin >> idOrigin;

	std::cout << "\n\t\t\t\tCity: ";
	std::string city;
	std::cin.ignore();
	std::getline(std::cin, city);

	std::cout << "\n\t\t\t\tStreet Address: ";
	std::string address;
	std::getline(std::cin, address);

	std::cout << "\n\t\t\t\tZip Code: ";
	std::string zipCode;
	std::getline(std::cin, zipCode);

	Address origin(address, zipCode, city, company.getCountriesToOperate()[idOrigin-1]);
	address.clear();
	zipCode.clear();
	city.clear();

	std::cout << "\n\n\t\t\t\t\t     DESTINATION INFO:\n";

	std::cout << "\n\t\t\tSelect from the list of Countries the one where the package will be received.\n\n";
	company.printCountriesToOperateFrom(company.getCountriesToOperate()[idOrigin-1]);

	int idDestination;
	std::cout << "\n\n\t\t\t\tCountry: ";
	std::cin >> idDestination;

	std::cout << "\n\t\t\t\tCity: ";
	std::cin.ignore();
	std::getline(std::cin, city);

	std::cout << "\n\t\t\t\tStreet Address: ";
	std::getline(std::cin, address);

	std::cout << "\n\t\t\t\tZip Code: ";
	std::getline(std::cin, zipCode);

	Address destination(address, zipCode, city, company.getCountryDestination(company.getCountriesToOperate()[idOrigin-1], idDestination));

	//std::cout << company.getCountryDestination(company.getCountriesToOperate()[idOrigin-1], idDestination).getName();

	int day, month, year, hour, minute;
	std::cout << "\n\n\t\t\t\t\t\tDATE INFO:" << std::endl;
	std::cout << "\n\n\t\t\t\tDay: ";
	std::cin >> day;
	std::cout << "\n\n\t\t\t\tMonth: ";
	std::cin >> month;
	std::cout << "\n\n\t\t\t\tYear: ";
	std::cin >> year;
	std::cout << "\n\n\t\t\t\tHour: ";
	std::cin >> hour;
	std::cout << "\n\n\t\t\t\tMinute: ";
	std::cin >> minute;

	Date begginingDate(day, month, year, hour, minute);

	/* CHECK INSERTED DATE */
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d %m %y %H %M", timeinfo);

	int day_now, month_now, year_now, hour_now, minute_now;
	std::string bufs(buffer);
	std::stringstream aux;

	aux << bufs;

	aux >> day_now;
	aux >> month_now;
	aux >> year_now;
	aux >> hour_now;
	aux >> minute_now;

	year_now += 2000;

	if(year < year_now){
		std::cout << "Invalid year";
		return 0;
	}

	else if(year == year_now){
		if(month < month_now){
			std::cout << "Invalid Month";
			return 0;
		}
		if(month == month_now){
			if(day < day_now){
				std::cout << "Invalid Day";
				return 0;
			}
		}
	}

	std::string response;
	std::cin.ignore();
	std::cout << "\n\t\t\t\tDo the volumes need warehousing? [y | n] : ";
	std::getline(std::cin, response);

	if(response == "n" || response == "N"){				//TRANSPORT
		//isto deve ser random!!!!

		/**** PACKING ******/
		Date packingB = begginingDate;
		packingB.setHour(hour+2);
		Date packingE = begginingDate;
		packingE.setDay(day+1);

		/**** SHIPPING *****/
		int zone1days = 5;
		int zone2days = 15;

		Date shippingB = begginingDate;
		shippingB.setDay(day+1); shippingB.setHour(hour+3);
		Date shippingE = begginingDate;

		/*** DELIVERY ****/
		Date deliveryB = begginingDate;
		Date deliveryE;
		Date endingDate;
																			//VERIFICAR DIAS
		if(destination.getCountry().getZone() == 1){
			shippingE.setDay(day+zone1days);					//ZONE 1  -> TIME OF SHIPPING
			if(hour < 12){
				deliveryB.setDay(day+zone1days);
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
			else{
				deliveryB = shippingE;
				deliveryB.setDay(day+zone1days+1);
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
		}
		else{
			shippingE.setDay(day+zone2days);					//ZONE 2  -> TIME OF SHIPPING
			if(hour < 12){
				deliveryB = shippingE;
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
			else{
				deliveryB.setDay(day+zone2days+1);
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
		}

		Transport* svcT = new Transport(origin, destination, weight, begginingDate, endingDate);
		int idT = svcT->getID();

		Packaging* p = new Packaging(packingB, packingE, weight, idT);
		Shipping* s = new Shipping(shippingB, shippingE, weight, idT);
		Delivery* d = new Delivery(deliveryB, deliveryE, weight, idT);

		svcT->setPackaging(p);
		svcT->setShipping(s);
		svcT->setDelivery(d);

		svcT->addBaseRate(company.getCountryDestination(company.getCountriesToOperate()[idOrigin-1], idDestination).getBaseRate());

		std::cout << "\n\t\t\t\tChoose the type of payment:\n" << std::endl;

		int option;

		if(company.getClients()[idClient-1]->isParticular()){		//PARTICULAR

			std::cout << "\t\t\t\t\t\t1 - ATM" << std::endl;
			std::cout << "\t\t\t\t\t\t2 - Bank Transfer\n" << std::endl;
			std::cout << "\t\t\t\t\t\t   Option: ";

			std::cin >> option;

			while(std::cin.fail()){
				std::cout << "\t\t\t\t\t\tNot a valid option.";
				std::cout << "\t\t\t\t\t\t    Option: ";
				std::cin >> option;
			}

			if(option == 1){							//ATM
				ATM* atm = new ATM(company.getEntity());
				svcT->setPayment(atm);

				std::cout << "\n\t\t\t\t\tPAYMENT DETAILS:\n" << std::endl;
				std::cout << "\n\t\t\t\t    Entity: ";
				std::cout << atm->getEntity();
				std::cout << "\n\t\t\t\t    Reference: ";
				std::cout << atm->getReference();
				std::cout << "\n\t\t\t\t    Montant: ";
				std::cout << svcT->getTotalCost();
			}

			else if(option == 2){						// Bank Transfer
				BankTransfer* bt = new BankTransfer(company.getIBAN());
				svcT->setPayment(bt);

				std::cout << "\n\t\t\t\t\tPAYMENT DETAILS:\n" << std::endl;
				std::cout << "\n\t\t\t\t   IBAN: " << bt->getIBAN();
				std::cout << "\n\t\t\t\t   Montant: " << svcT->getTotalCost();

			}
			else if(option == 0) return 0;

			else if(option == -1) return -1;

		}
		else{															//COMPANY
			std::cout << "\t\t\t\t\t\t1 - ATM" << std::endl;
			std::cout << "\t\t\t\t\t\t2 - Credit Card" << std::endl;
			std::cout << "\t\t\t\t\t\t3 - Bank Transfer" << std::endl;
			std::cout << "\n\t\t\t\t\t4 - End of the Month" << std::endl;

			std::cin >> option;

			while(std::cin.fail()){
				std::cout << "\t\t\t\t\t\tNot a valid option.";
				std::cout << "\t\t\t\t\t\t    Option: ";
				std::cin >> option;
			}

			if(option == 1){					//ATM
				ATM* atm = new ATM(company.getEntity());
				svcT->setPayment(atm);

				std::cout << "\n\t\t\t\t\tPAYMENT DETAILS:\n" << std::endl;
				std::cout << "\n\t\t\t\t    Entity: ";
				std::cout << atm->getEntity();
				std::cout << "\n\t\t\t\t    Reference: ";
				std::cout << atm->getReference();
				std::cout << "\n\t\t\t\t    Montant: ";
				std::cout << svcT->getTotalCost();

			}
			else if(option == 2){				//CREDIT CARD

				int month;
				std::string ccNumber;
				std::cout << "\n\t\t\t\t\tPAYMENT DETAILS:\n" << std::endl;
				std::cout << "\n\t\t\t\t Credit Card Number: ";
				std::cin >> ccNumber;

				std::cout << "\n\t\t\t\t Validation month: ";
				std::cin >> month;

				std::cout << "\n\t\t\t\t Montant: " << svcT->getTotalCost();

			}
			else if(option == 3){				//BANK TRANSFER

				BankTransfer* bt = new BankTransfer(company.getIBAN());
				svcT->setPayment(bt);

				std::cout << "\n\t\t\t\t\tPAYMENT DETAILS:\n" << std::endl;
				std::cout << "\n\t\t\t\t   IBAN: " << bt->getIBAN();
				std::cout << "\n\t\t\t\t   Montant: " << svcT->getTotalCost();

			}
			else if(option == 4){
				//------------------------>>>>>>>PAY AT THE END OF MONTH
			}
			else if(option == 0) return 0;

			else if(option == -1) return -1;

		}

		company.getClients()[idClient-1]->addNewService(svcT);

		//std::cout << "COST" << svcT->getTotalCost();		-->>CERTO!!!
		//std::cout << *company.getClients()[idClient-1]->getServicesRequested()[2];

	}
	else if(response == "y" || response == "Y"){					//WAREHOUSING

		int daysWarehouse;

		std::cout << "\n\t\t\t\tHow many days will the volumes be in the warehouse? ";
		std::cin >> daysWarehouse;

		/**** PACKING ******/
		Date packingB = begginingDate;
		packingB.setHour(hour+2);
		Date packingE = begginingDate;
		packingE.setDay(day+1);

		/**** SHIPPING *****/
		int zone1days = 5;
		int zone2days = 15;

		Date shippingB = begginingDate;
		shippingB.setDay(day+1); shippingB.setHour(hour+3);
		Date shippingE = begginingDate;

		/*** DELIVERY ****/
		Date deliveryB = begginingDate;
		Date deliveryE;
		Date endingDate;
																			//VERIFICAR DIAS
		if(destination.getCountry().getZone() == 1){
			shippingE.setDay(day+zone1days);					//ZONE 1  -> TIME OF SHIPPING
			if(hour < 12){
				deliveryB.setDay(day+zone1days+daysWarehouse);		//+daysWarehouse
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
			else{
				deliveryB = shippingE;
				deliveryB.setDay(day+zone1days+1+daysWarehouse);		//+daysWarehouse
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
		}
		else{
			shippingE.setDay(day+zone2days);					//ZONE 2  -> TIME OF SHIPPING
			if(hour < 12){
				deliveryB = shippingE;						//+daysWarehouse
				deliveryB.setDay(day+zone1days+1+daysWarehouse);
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
			else{
				deliveryB.setDay(day+zone2days+1+daysWarehouse);			//+daysWarehouse
				deliveryE = deliveryB;
				deliveryE.setHour(hour+5);
				endingDate = deliveryE;
			}
		}

		Warehousing* svcW = new Warehousing(origin, destination, weight, begginingDate, endingDate, daysWarehouse);
		int idW = svcW->getID();

		Packaging* p = new Packaging(packingB, packingE, weight, idW);
		Shipping* s = new Shipping(shippingB, shippingE, weight, idW);
		Delivery* d = new Delivery(deliveryB, deliveryE, weight, idW);

		svcW->setPackaging(p);
		svcW->setShipping(s);
		svcW->setDelivery(d);

		company.getClients()[idClient-1]->addNewService(svcW);

		std::cout << *company.getClients()[idClient-1]->getServicesRequested()[2];
	}

	else if(response == "0") return 0;

	else if(response == "-1") return -1;

	else{
		std::cout << "\n\t\t\t\tNot a valid entry." << std::endl;
		return 0;
	}

	return 0;
}

int newUnregisteredClientService(MovingCompany& company){

	return 0;
}

int newService(MovingCompany& company){

	int option;

	std::cout << "\n\n\t\t\t\t\t\t\tREQUEST NEW SERVICE FORM\n" << std::endl;
	std::cout << "\t\t\tPlease enter if you want to request a service to an already REGISTERED client or to an UNREGISTERED client." << std::endl;
	std::cout << "\n\t\t\t\t\t\t\t1 - Registered Client" << std::endl;
	std::cout << "\t\t\t\t\t\t\t2 - Unregistered Client\n" << std::endl;
	std::cout << "\t\t\t\t\t\t\t0 - Go back" << std::endl;
	std::cout << "\t\t\t\t\t\t       -1 - Exit Program\n" << std::endl;

	std::cout << "\n\t\t\t\t\tPlease enter an option: ";
	std::cin >> option;

	while(option != -1){
		int instruction;

		switch(option){
			case 1:
				instruction = newRegisteredClientService(company);
				break;
			case 2:
				instruction = newUnregisteredClientService(company);
				break;
			case 0:
				return 0;
			case -1:
				return -1;
		}
		if(!instruction) continue;
		if(instruction == -1) return -1;
	}
	return -1;
}

int printClientsServices(MovingCompany& company){
	/*
	int option;

	std::cout << "\n\n\t\t\t\t\t\t\tPRINT CLIENT SERVICES\n" << std::endl;
	std::cout << "Enter the ID of the client to check the services: ";

	std::cin >> option;

	while(option != -1){
		int instruction;

		switch(option){
			case 1
		}
	}

	return -1;*/
	int id;

	std::cout << "\n\n\t\t\t\t\t\t\tPRINT CLIENT SERVICES\n" << std::endl;
	std::cout << "Enter the ID of the client to check the services: ";

	std::cin >> id;

	company.printClientServices(id);
}



