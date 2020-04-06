#pragma once
#include <iostream>
#include "BanksView.h"
#include "ClientsView.h"

using namespace std;

class MainView
{
private:
	BanksView _banksView;
	ClientsView _clientsView;
public:
	MainView();
	MainView(vector<Bank>* banks);
	~MainView();

	void Show();
};

