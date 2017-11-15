/*
 * ImportInfo.cpp
 *
 *  Created on: 14/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ImportInfo.h"

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
			float baseRate;
			std::stringstream auxSS;

			std::getline(ss, name, ' ');
			aux.clear();

			std::getline(ss, aux, '\n');
			auxSS << aux;
			auxSS >> baseRate;


			for(j = 0; j < company.getCountriesToOperate().size(); j++){
				if(company.getCountriesToOperate()[j]->getName() == name){
					//company.getCountriesToOperate()[i]->addZone1Country(company.getCountriesToOperate()[j]);
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
					//company.getCountriesToOperate()[i]->addZone2Country(company.getCountriesToOperate()[j]);
					ConnectionCountryInfo ci(company.getCountriesToOperate()[j], 2, baseRate);
					company.getCountriesToOperate()[i]->addCountryConnection(ci);
				}
			}

		}
	}

	/*for(unsigned int k = 0; k < company.getCountriesToOperate().size(); k++){
		std::cout << company.getCountriesToOperate()[k]->getName() << std::endl;
			for(unsigned int l = 0; l < company.getCountriesToOperate()[k]->getCountriesInfo().size(); l++){
				std::cout << company.getCountriesToOperate()[k]->getCountriesInfo()[l].getName() << " ";
				std::cout << company.getCountriesToOperate()[k]->getCountriesInfo()[l].getZone() << " ";
				std::cout << company.getCountriesToOperate()[k]->getCountriesInfo()[l].getBaseRate() << "ACABOU";
			}
		std::cout << std::endl << std::endl;
	}*/

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

void readAddress(MovingCompany& company, std::stringstream& auxSS, Address& address){

	std::string streetAddress, zipCode, city, countryName;

	std::getline(auxSS, streetAddress, '/');
	std::getline(auxSS, zipCode, '/');
	std::getline(auxSS, city, '/');
	std::getline(auxSS, countryName);

	address.setStreet(streetAddress);
	address.setZipCode(zipCode);
	address.setCity(city);
	address.setCountry(company.getCountry(countryName)->getName());
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

		//Client* c = company.getClients()[idClient];

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
			readAddress(company, auxSS, origin);			// Origin Address

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, ']');
			auxSS << aux;
			Address destination;							// Destination Address
			readAddress(company, auxSS, destination);

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

			//------------------AUXILIAR
			/*std::cout << begginingTransport;
			std::cout << endTransport;
			std::cout << origin.getCity();
			std::cout << destination.getCity();
			std::cout << "\nEND TIME: " << endTransport.getHour()<<" "<< endTransport.getMinute();
			std::cout <<"PACKAGING" << packagingB.getDay() << packagingB.getMinute();
			std::cout <<"PACKAGING" << packagingE.getDay() << packagingE.getMinute();
			std::cout << "\nSHIPPING" << shippingB.getDay() << shippingE.getMinute();
			std::cout << "\nDELIVERY" << deliveryB.getDay() << deliveryE.getMinute();*/
			//--------------------------


			Transport* svcT = new Transport(origin, destination, weight, begginingTransport, endTransport);
			int idT = svcT->getID();

			Packaging* p = new Packaging(packagingB, packagingE, weight, idT);
			Shipping* s = new Shipping(shippingB, shippingE, weight, idT);
			Delivery* d = new Delivery(deliveryB, deliveryE, weight, idT);

			svcT->setPackaging(p);
			svcT->setShipping(s);
			svcT->setDelivery(d);

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
			readAddress(company, auxSS, origin);			// Origin Address

			aux.clear();
			auxSS.clear();				//Clear buffers
			auxSS.str(std::string());

			std::getline(ss, aux, ']');
			auxSS << aux;
			Address destination;							// Destination Address
			readAddress(company, auxSS, destination);

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
/*
			//------------------AUXILIAR
			std::cout << begginingTransport;
			std::cout << endTransport;
			std::cout << origin.getCity();
			std::cout << destination.getCity();
			std::cout << "\nEND TIME: " << endTransport.getHour()<<" "<< endTransport.getMinute();
			std::cout <<"PACKAGING" << packagingB.getDay() << packagingB.getMinute();
			std::cout <<"PACKAGING" << packagingE.getDay() << packagingE.getMinute();
			std::cout << "\nSHIPPING" << shippingB.getDay() << shippingE.getMinute();
			std::cout << "\nDELIVERY" << deliveryB.getDay() << deliveryE.getMinute();
			//--------------------------
*/
			Warehousing* svcW = new Warehousing(origin, destination, begginingWarehousing, endWarehousing, weight, daysWarehousing);
			int idW = svcW->getID();

			Packaging* p = new Packaging(packagingB, packagingE, weight, idW);
			Shipping* s = new Shipping(shippingB, shippingE, weight, idW);
			Delivery* d = new Delivery(deliveryB, deliveryE, weight, idW);

			svcW->setPackaging(p);
			svcW->setShipping(s);
			svcW->setDelivery(d);

			company.getClients()[idClient]->addNewService(svcW);
		}
	}
}




