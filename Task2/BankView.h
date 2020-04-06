#pragma once
#include <iostream>
#include "Bank.h"
#include "ClientView.h"

using namespace std;

class BankView
{
private:
	ClientView _clientView;
public:	
	BankView();
	BankView(vector<Bank>* banks);
	~BankView();

	void Show(Bank* bank);
	void PrintClients(Bank* bank);
	int GetClientIndex(int size);
	int GetClientType();
	std::string GetClientInfo(std::string placeholder);
};

