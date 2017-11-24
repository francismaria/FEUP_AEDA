/*
 * ImportInfo.cpp
 *
 *  Created on: 14/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ImportInfo.h"

void importClients(MovingCompany& company, int& numberOfExistentClients){

	std::ifstream clientsFile;
	clientsFile.open("InfoFiles/clients.txt");

	if(!clientsFile.good())
		std::cout << "Couldn't access clients.txt file. Error reading from File." << std::endl;

	int fDay, fMonth, fYear, fHour, fMinute, age;
	long int nif;
	std::string name, zipCode, address, line, city, country, clientType;

	while(std::getline(clientsFile, line)){

		std::stringstream ss(line);
		std::string aux;
		std::stringstream auxSS;

		std::getline(ss, clientType, '/');

		if(clientType == "P"){				//PARTICULAR

			// Name
			std::getline(ss, name, '/');

			// Age
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> age;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// NIF
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> nif;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Address
			std::getline(ss, address, '/');

			// Zip Code
			std::getline(ss, zipCode, '/');

			// City
			std::getline(ss, city, '/');

			// Country
			std::getline(ss, country, '/');

			// Day
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> fDay;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Month
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> fMonth;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Year
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> fYear;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Hour
			std::getline(ss, aux, ':');
			auxSS << aux;
			auxSS >> fHour;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Minute
			std::getline(ss, aux, ':');
			auxSS << aux;
			auxSS >> fMinute;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			Particular* p = new Particular(name, age, nif, address, zipCode, city, country, fDay, fMonth, fYear, fHour, fMinute);
			company.addClient(p);
		}
		else if(clientType == "C"){					//COMPANY

			//	Name
			std::getline(ss, name, '/');

			// NIF
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> nif;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Address
			std::getline(ss, address, '/');

			// ZipCode
			std::getline(ss, zipCode, '/');

			// City
			std::getline(ss, city, '/');

			// Country
			std::getline(ss, country, '/');

			// Day
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> fDay;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Month
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> fMonth;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Year
			std::getline(ss, aux, '/');
			auxSS << aux;
			auxSS >> fYear;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Hour
			std::getline(ss, aux, ':');
			auxSS << aux;
			auxSS >> fHour;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			// Minute
			std::getline(ss, aux);
			auxSS << aux;
			auxSS >> fMinute;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			Company* c = new Company(name, nif, address, zipCode, city, country, fDay, fMonth, fYear, fHour, fMinute);
			company.addClient(c);
		}
	}

	clientsFile.close();

	numberOfExistentClients = company.getClients().size();
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
			float baseRate;
			std::stringstream auxSS;

			std::getline(ss, name, ' ');
			aux.clear();

			std::getline(ss, aux, '\n');
			auxSS << aux;
			auxSS >> baseRate;


			for(j = 0; j < company.getCountriesToOperate().size(); j++){
				if(company.getCountriesToOperate()[j]->getName() == name){
					ConnectionCountryInfo ci(company.getCountriesToOperate()[j], 1, baseRate);
					company.getCountriesToOperate()[i]->addCountryConnection(ci);
				}
			}
		}
		else{
			//zone2
			std::string name;
			float baseRate;
			std::stringstream auxSS;

			std::getline(ss, name, ' ');
			aux.clear();

			std::getline(ss, aux, '\n');
			auxSS << aux;
			auxSS >> baseRate;

			for(j = 0; j < company.getCountriesToOperate().size(); j++){
				if(company.getCountriesToOperate()[j]->getName() == name){
					ConnectionCountryInfo ci(company.getCountriesToOperate()[j], 2, baseRate);
					company.getCountriesToOperate()[i]->addCountryConnection(ci);
				}
			}

		}
	}

	countriesZonesFile.close();
}

void readDate(std::stringstream& ss, Date& date){

	int day, month, year, hour, minute;
	std::string buffer;
	std::stringstream auxSS;

	std::getline(ss, buffer, '-');
	auxSS << buffer;
	auxSS >> day;

	buffer.clear();
	auxSS.clear();				//Clears Buffers
	auxSS.str(std::string());

	std::getline(ss, buffer, '-');
	auxSS << buffer;
	auxSS >> month;

	buffer.clear();
	auxSS.clear();				//Clears Buffers
	auxSS.str(std::string());

	std::getline(ss, buffer, '-');
	auxSS << buffer;
	auxSS >> year;

	buffer.clear();
	auxSS.clear();				//Clears Buffers
	auxSS.str(std::string());

	std::getline(ss, buffer, ':');
	auxSS << buffer;
	auxSS >> hour;

	buffer.clear();
	auxSS.clear();				//Clears Buffers
	auxSS.str(std::string());


	std::getline(ss, buffer);
	auxSS << buffer;
	auxSS >> minute;

	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);
	date.setHour(hour);
	date.setMinute(minute);
}

int readAddress(MovingCompany& company, std::stringstream& auxSS, Address& address){

	std::string streetAddress, zipCode, city, countryName;

	std::getline(auxSS, streetAddress, '/');
	std::getline(auxSS, zipCode, '/');
	std::getline(auxSS, city, '/');
	std::getline(auxSS, countryName);

	address.setStreet(streetAddress);
	address.setZipCode(zipCode);
	address.setCity(city);
	address.setCountry(company.getCountry(countryName)->getName());

	for(unsigned int i = 0; i < company.getCountriesToOperate().size(); i++){
		if(countryName == company.getCountriesToOperate()[i]->getName())
			return i+1;
	}
}

void importServices(MovingCompany& company){

	std::ifstream servicesFile;
	servicesFile.open("InfoFiles/services.txt");

	if(!servicesFile.good())
		std::cout << "Couldn't access services.txt file. Error reading from File." << std::endl;

	int idClient;
	std::string line;

	while(std::getline(servicesFile, line)){

		std::stringstream ss(line);
		std::string aux;
		std::stringstream auxSS;

		std::getline(ss, aux, '/');
		auxSS << aux;
		auxSS >> idClient;

		aux.clear();				//Clears buffers
		auxSS.clear();
		auxSS.str(std::string());

		std::getline(ss, aux, '/');

		int weight;

		if(aux == "T"){						//TRANSPORT
			aux.clear();
			std::getline(ss, aux, '/');
			auxSS << aux;					//WEIGHT
			auxSS >> weight;

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			Date begginingTransport;
			Date endTransport;

			std::getline(ss, aux, '/');
			auxSS << aux;
			readDate(auxSS, begginingTransport);			//beggining Date Transport

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '[');
			auxSS << aux;
			readDate(auxSS, endTransport);					//ending Date Transport

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/************* ADDRESS ***************/
			std::getline(ss, aux, ']');
			auxSS << aux;
			Address origin;
			int idOrigin = readAddress(company, auxSS, origin);			// Origin Address

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, ']');
			auxSS << aux;
			Address destination;// Destination Address
			int idDestination = readAddress(company, auxSS, destination);
			idDestination--;

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/************ PACKAGING ***************/
			ss.ignore(line.length(), '/');
			std::getline(ss, aux, '/');
			auxSS << aux;

			Date packagingB, packagingE;
			readDate(auxSS, packagingB);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '/');
			auxSS << aux;

			readDate(auxSS, packagingE);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/*********** SHIPPING ***********/
			ss.ignore(line.length(), '/');
			std::getline(ss, aux, '/');
			auxSS << aux;

			Date shippingB, shippingE;
			readDate(auxSS, shippingB);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '/');
			auxSS << aux;

			readDate(auxSS, shippingE);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/*********** DELIVERY ***********/
			ss.ignore(line.length(), '/');
			std::getline(ss, aux, '/');
			auxSS << aux;

			Date deliveryB, deliveryE;
			readDate(auxSS, deliveryB);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '/');
			auxSS << aux;

			readDate(auxSS, deliveryE);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::string typePayment;

			std::getline(ss, typePayment, '/');

			Payment* pay;

			if(typePayment == "ATM"){
				pay = new ATM(company.getEntity());
			}
			else if(typePayment == "CC"){
				pay = new CreditCard();
			}
			else if(typePayment == "BT"){
				pay = new BankTransfer(company.getIBAN());
			}
			else if(typePayment == "EOM"){
				int actualMonth;
				time_t rawtime;
				struct tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);
				strftime(buffer, sizeof(buffer), "%m", timeinfo);

				std::string buf(buffer);

				ss << buf;
				ss >> actualMonth;

				pay = new EndOfMonth(actualMonth);
			}

			std::string paymentStatus;
			std::getline(ss, paymentStatus);

			if(paymentStatus == "RECEIVED"){
				pay->validate();
			}

			Transport* svcT = new Transport(origin, destination, weight, begginingTransport, endTransport);
			int idT = svcT->getID();

			Packaging* p = new Packaging(packagingB, packagingE, weight, idT);
			Shipping* s = new Shipping(shippingB, shippingE, weight, idT);
			Delivery* d = new Delivery(deliveryB, deliveryE, weight, idT);

			svcT->setPackaging(p);
			svcT->setShipping(s);
			svcT->setDelivery(d);
			svcT->setPayment(pay);

			svcT->addBaseRate(company.getCountryDestination(company.getCountriesToOperate()[idOrigin-1], idDestination).getBaseRate());

			company.getClients()[idClient]->addNewService(svcT);
		}
		if(aux == "W"){

			aux.clear();
			int daysWarehousing;

			std::getline(ss, aux, '/');

			auxSS << aux;
			auxSS >> daysWarehousing;

			aux.clear();
			auxSS.clear();
			auxSS.str(std::string());

			std::getline(ss, aux, '/');
			auxSS << aux;					//WEIGHT
			auxSS >> weight;

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/************** DATES *****************/
			Date begginingWarehousing;
			Date endWarehousing;

			std::getline(ss, aux, '/');
			auxSS << aux;
			readDate(auxSS, begginingWarehousing);			//beggining Date Transport

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '[');
			auxSS << aux;
			readDate(auxSS, endWarehousing);					//ending Date Transport

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/************* ADDRESS ***************/
			std::getline(ss, aux, ']');
			auxSS << aux;
			Address origin;
			int idOrigin = readAddress(company, auxSS, origin);			// Origin Address

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, ']');
			auxSS << aux;
			Address destination;							// Destination Address
			int idDestination = readAddress(company, auxSS, destination);
			idDestination--;

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/************ PACKAGING ***************/
			ss.ignore(line.length(), '/');
			std::getline(ss, aux, '/');
			auxSS << aux;

			Date packagingB, packagingE;
			readDate(auxSS, packagingB);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '/');
			auxSS << aux;

			readDate(auxSS, packagingE);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/*********** SHIPPING ***********/
			ss.ignore(line.length(), '/');
			std::getline(ss, aux, '/');
			auxSS << aux;

			Date shippingB, shippingE;
			readDate(auxSS, shippingB);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '/');
			auxSS << aux;

			readDate(auxSS, shippingE);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			/*********** DELIVERY ***********/
			ss.ignore(line.length(), '/');
			std::getline(ss, aux, '/');
			auxSS << aux;

			Date deliveryB, deliveryE;
			readDate(auxSS, deliveryB);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, '/');
			auxSS << aux;

			readDate(auxSS, deliveryE);

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::string typePayment;
			std::getline(ss, typePayment, '/');

			Payment* pay;

			if(typePayment == "ATM"){
				pay = new ATM(company.getEntity());
			}
			else if(typePayment == "Credit Card"){
				pay = new CreditCard();
			}
			else if(typePayment == "Bank Transfer"){
				pay = new BankTransfer(company.getIBAN());
			}
			else if(typePayment == "Payable until the end of month"){
				int actualMonth;
				time_t rawtime;
				struct tm* timeinfo;
				char buffer[80];

				time(&rawtime);
				timeinfo = localtime(&rawtime);
				strftime(buffer, sizeof(buffer), "%m", timeinfo);

				std::string buf(buffer);

				ss << buf;
				ss >> actualMonth;

				pay = new EndOfMonth(actualMonth);
			}

			//---- Payment Status
			std::string paymentStatus;
			std::getline(ss, paymentStatus);

			if(paymentStatus == "RECEIVED")
				pay->validate();

			Warehousing* svcW = new Warehousing(origin, destination, weight, begginingWarehousing, endWarehousing, daysWarehousing);
			int idW = svcW->getID();

			Packaging* p = new Packaging(packagingB, packagingE, weight, idW);
			Shipping* s = new Shipping(shippingB, shippingE, weight, idW);
			Delivery* d = new Delivery(deliveryB, deliveryE, weight, idW);

			svcW->setPackaging(p);
			svcW->setShipping(s);
			svcW->setDelivery(d);
			svcW->setPayment(pay);

			svcW->addBaseRate(company.getCountryDestination(company.getCountriesToOperate()[idOrigin-1], idDestination).getBaseRate());

			company.getClients()[idClient]->addNewService(svcW);
		}
	}
}




