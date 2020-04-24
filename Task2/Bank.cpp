#include "Bank.h"
#include "IndividualPerson.h"
#include "LegalPerson.h"
#include <iostream>

Bank::Bank(string name, float startAccount, float transferPercentage)
{
	_name = name;
	_account = startAccount;
	_transferPercentage = transferPercentage;
}

Bank::~Bank()
{
	_clients.clear();
}

void Bank::AddClient(string firstName, string secondName, int type)
{
	Client* client;

	if (type == 1)
		client = new IndividualPerson(firstName, secondName, this);
	else
		client = new LegalPerson(firstName, secondName, this);

	_clients.push_back(client);
}

void Bank::AddClient(Client* client)
{
	_clients.push_back(client);
}

void Bank::RemoveClient(int index)
{
	_clients.erase(_clients.begin() + index);
}

int Bank::GetClientsCount()
{
	return _clients.size();
}

Client* Bank::GetClient(int index)
{
	return _clients[index];
}

std::string Bank::GetName()
{
	return _name;
}

float Bank::GetAccount()
{
	return _account;
}

float Bank::GetTransferPercentage()
{
	return _transferPercentage;
}

Client*& Bank::operator[](const int index)
{
	return _clients[index];
}

void Bank::OnClientPut(float amount)
{
	if (amount < 1)
		throw std::exception("Ошибка! Попытка положить неверную сумму!");

	_account += amount;
}

void Bank::OnClientWidthdraw(float amount)
{
	if (amount > _account)
		throw std::exception("Ошибка! Попытка снять сумму больше, чем имеется на счёте банка.");

	_account -= amount;
}

void Bank::OnClientTransfer(float amount)
{
	_account += amount;
}

float Bank::CalculateTransfer(float amount)
{
	return amount * (1 + _transferPercentage / 100);
}

void Bank::Print()
{
	cout << "Банк: " << GetName() << "; " << "Сумма в банке: " << _account << "; Процент перевода: " << _transferPercentage << endl;
	if (_clients.size() < 1)
	{
		cout << "\t" << "Клиентов в банке нет!";
		return;
	}

	for (int i = 0; i < _clients.size(); i++)
	{
		cout << "\t" << i + 1 << ". ";
		_clients[i]->Print();
		cout << endl;
	}
}
