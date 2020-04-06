#pragma once
#include "Client.h"

class Client;
class Bank;

using namespace std;

class IndividualPerson : public Client
{
public:
	IndividualPerson(string firstName, string secondName, Bank* bank) : Client(firstName, secondName, bank) {};
	void Print();
};

