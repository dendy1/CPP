#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ClientView.h"

using namespace std;

class ClientView;
class Bank;
class Client;

class ClientsView
{
private:
	ClientView _clientView;
	vector<Bank>* _banks;
public:
	ClientsView();
	ClientsView(vector<Bank>* banks);
	~ClientsView();

	void PrintClients();
	int GetBankIndex();
	int GetClientIndex(int size);
	int GetClientType();
	vector<Client*> GetAllClients();
	string GetClientInfo(std::string placeholder);

	void Show();
};

