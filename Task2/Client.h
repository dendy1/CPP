#pragma once
#include <vector>
#include <string>

class Bank;

class Client
{
protected:
	Bank* _bank;
	std::string _firstName;
	std::string _secondName;
	float _account;

public:
	Client(std::string firstName, std::string secondName, Bank* bank);
	~Client();

	void PutMoney(float amount);
	void WithdrawMoney(float amount);
	std::string GetFirstName();
	std::string GetSecondName();
	float GetAccount();

	virtual void Print() = 0;
};