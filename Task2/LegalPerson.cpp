#include "LegalPerson.h"
#include "Bank.h"

void LegalPerson::TransferMoney(Client* client, float amount)
{
	float account = (*_bank).CalculateTransfer(amount);
	WithdrawMoney(account);
	_bank->OnClientTransfer(account - amount);
	client -> PutMoney(amount);
}
#include <iostream>

void LegalPerson::Print()
{
	std::cout << "ёридическое лицо. " << _firstName << " " << _secondName << "; " << _account;
}
