/*
 * Client.h
 *
 *  Created on: 31/10/2017
 *      Author: Francisco Maria / João Gama Amaral
 */

#ifndef CLIENT_H_
#define CLIENT_H_

class Client{
	int id;
	int age;
	long int NIF;
	std::string name;
	std::string address;
	//Date joiningDate; --> inicializador de membro obrigatório!!
	static int numberOfClients;
public:
	Client(int id, int age, std::string name, long int nif, std::string address);
	int getId() const;
	int getAge() const;
	long int getNIF() const;
	std::string getName() const;
	std::string getAddress() const;
	static int getNumberOfClients();

};

class Company: public Client{

};

class Particular: public Client{

};

class ClienteNaoExistente{
public:
	std::string name;
	ClienteNaoExistente(std::string n){ name = n; }
	std::string getName(){ return name; }
};


#endif /* CLIENT_H_ */
