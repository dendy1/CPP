#pragma once
#include "Client.h"
#include "IndividualPerson.h"
#include "LegalPerson.h"
#include <iostream>

using namespace std;

class ClientView
{
private :
	vector<Bank>* _banks;

public:
	ClientView();
	ClientView(vector<Bank>* banks);
	void Show(Client* client);
	float GetAmount();
	void PrintClients();
	int GetBankIndex();
	int GetClientIndex(int size);
};

