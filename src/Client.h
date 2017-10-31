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
public:
	Client(int id, int age, std::string name);
	int getId() const;
	int getAge() const;
	long int getNIF() const;
	std::string getName() const;

};

class Company: public Client{

};

class Particular: public Client{

};


#endif /* CLIENT_H_ */
