#pragma once
#include <iostream>
#include <vector>
#include "Bank.h"
#include "BankView.h"

using namespace std;

class BanksView
{
private:
	BankView _bankView;
	vector<Bank> *_banks;

	string GetBankName();
	float GetStartAccount();
	float GetTransferPercentage();
public:
	BanksView();
	BanksView(vector<Bank>* banks);
	~BanksView();

	void PrintBanks();
	int GetBankIndex();

	void Show();
};

