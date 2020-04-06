#pragma once
#include "Client.h"

class Client;
class Bank;

using namespace std;

class LegalPerson : public Client
{
public:
	LegalPerson(string firstName, string secondName, Bank* bank) : Client(firstName, secondName, bank) {};
	void TransferMoney(Client* client, float amount);
	void Print();
};

