#include "Bank.h"
#include "Client.h"

Client::Client(std::string firstName, std::string secondName, Bank* bank)
{
	_firstName = firstName;
	_secondName = secondName;
	_bank = bank;
	_account = 0;
}

Client::~Client()
{
}

void Client::PutMoney(float amount)
{
	if (amount < 1)
		throw std::exception("Ошибка! Попытка положить неверную сумму!");

	_bank -> OnClientPut(amount);
	_account += amount;
}

void Client::WithdrawMoney(float amount)
{
	if (amount > _account)
		throw std::exception("Ошибка! Попытка снять сумму больше, чем имеется на счёте клиента.");

	_bank -> OnClientWidthdraw(amount);
	_account -= amount;
}

std::string Client::GetFirstName()
{
	return _firstName;
}

std::string Client::GetSecondName()
{
	return _secondName;
}

float Client::GetAccount()
{
	return _account;
}
