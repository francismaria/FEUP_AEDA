/*
 * ExportInfo.cpp
 *
 *  Created on: 16/11/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#include "ExportInfo.h"

std::string saveParticularClient(Client* c){

	std::string line;
	std::stringstream ss;
	std::string delimiter = "/";

	line = "\nP/";

	// Name
	std::string name;
	name = c->getName();

	// Age
	std::string age;
	int auxAge = c->getAge();
	ss << auxAge;
	ss >> age;

	ss.clear();
	ss.str(std::string());

	// NIF
	std::string nif;
	int auxNif = c->getNIF();
	ss << auxNif;
	ss >> nif;

	ss.clear();
	ss.str(std::string());

	// Street Address
	std::string streetAddress;
	streetAddress = c->getAddress().getStreet();

	// Zip Code
	std::string zipCode;
	zipCode = c->getAddress().getZipCode();

	// City
	std::string city;
	city = c->getAddress().getCity();

	// Country
	std::string country;
	country = c->getAddress().getCountryAux();

	// Day
	std::string day;
	int auxDay = c->getJoiningDate().getDay();
	ss << auxDay;
	ss >> day;

	ss.clear();
	ss.str(std::string());

	// Month
	std::string month;
	int auxMonth = c->getJoiningDate().getMonth();
	ss << auxMonth;
	ss >> month;

	ss.clear();
	ss.str(std::string());

	// Year
	std::string year;
	int auxYear = c->getJoiningDate().getYear();
	ss << auxYear;
	ss >> year;

	ss.clear();
	ss.str(std::string());

	//Hour
	std::string hour;
	int auxHour = c->getJoiningDate().getHour();
	ss << auxHour;
	ss >> hour;

	ss.clear();
	ss.str(std::string());


	//Minute
	std::string min;
	int auxMin = c->getJoiningDate().getMinute();
	ss << auxMin;
	ss >> min;

	ss.clear();
	ss.str(std::string());

	line.append(name).append(delimiter).append(age).append(delimiter).append(nif).append(delimiter).append(streetAddress).
			append(delimiter).append(zipCode).append(delimiter).append(city).append(delimiter).append(country).append(delimiter).
			append(day).append(delimiter).append(month).append(delimiter).append(year).append(delimiter).append(hour).
			append(":").append(min);

	return line;
}

std::string saveCompanyClient(Client* c){

	std::string line;
	std::stringstream ss;
	std::string delimiter = "/";

	line = "\nC/";

	//Name
	std::string name;
	name = c->getName();

	//NIF
	std::string nif;
	int auxNif = c->getNIF();
	ss << auxNif;
	ss >> nif;

	ss.clear();
	ss.str(std::string());

	//Address
	std::string streetAddress;
	streetAddress = c->getAddress().getStreet();

	std::cout << streetAddress;

	//ZipCode
	std::string zipCode;
	zipCode = c->getZipCode();

	//City
	std::string city;
	city = c->getAddress().getCity();

	//Country
	std::string country;
	country = c->getAddress().getCountryAux();

	// Day
	std::string day;
	int auxDay = c->getJoiningDate().getDay();
	ss << auxDay;
	ss >> day;

	ss.clear();
	ss.str(std::string());

	// Month
	std::string month;
	int auxMonth = c->getJoiningDate().getMonth();
	ss << auxMonth;
	ss >> month;

	ss.clear();
	ss.str(std::string());

	// Year
	std::string year;
	int auxYear = c->getJoiningDate().getYear();
	ss << auxYear;
	ss >> year;

	ss.clear();
	ss.str(std::string());

	//Hour
	std::string hour;
	int auxHour = c->getJoiningDate().getHour();
	ss << auxHour;
	ss >> hour;

	ss.clear();
	ss.str(std::string());

	//Minutes
	std::string min;
	int auxmin = c->getJoiningDate().getMinute();
	ss << auxmin;
	ss >> min;

	ss.clear();
	ss.str(std::string());

	line.append(name).append(delimiter).append(nif).append(delimiter).append(streetAddress).
				append(delimiter).append(zipCode).append(delimiter).append(city).append(delimiter).append(country).append(delimiter).
				append(day).append(delimiter).append(month).append(delimiter).append(year).append(delimiter).append(hour).
				append(":").append(min);

	return line;
}

void saveClients(MovingCompany& company, int newClients){

	int i;
	int clientsSize = company.getClients().size();
	int startIndex = clientsSize - newClients;

	std::ofstream clientsFile;
	clientsFile.open("InfoFiles/clients.txt", std::ios::app);

	for(i = startIndex; i < clientsSize; i++){

		std::string infoClient;
		Client* c = company.getClients()[i];

		if(company.getClients()[i]->isParticular()){
			infoClient = saveParticularClient(c);
		}
		else{
			infoClient = saveCompanyClient(c);
		}

		clientsFile << infoClient;
	}

	clientsFile.close();
}



