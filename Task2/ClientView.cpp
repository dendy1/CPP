#include "ClientView.h"
#include "Bank.h"

ClientView::ClientView()
{
	_banks = &(vector<Bank>());
}

ClientView::ClientView(vector<Bank>* banks)
{
	_banks = banks;
}

void ClientView::Show(Client* client)
{
	cout << "====" << client->GetFirstName() << " " << client->GetSecondName() << " Menu====" << endl;
	cout << "1. Полная информация о клиенте (введите 1)" << endl;
	cout << "2. Снять сумму со счета (введите 2)" << endl;
	cout << "3. Положить сумму на счет (введите 3)" << endl;
	if (dynamic_cast<LegalPerson*>(client))
		cout << "4. Перевести сумму на счёт (введите 4)" << endl;
	cout << "-1. Выход (введите -1)" << endl;
	cout << "Ваш выбор: ";

	int opt;
	cin >> opt;

	cout << "=================" << endl;
	switch (opt)
	{
	case 1:
	{
		client->Print();
		break;
	}
	case 2:
	{
		try
		{
			float amount = GetAmount();
			client->WithdrawMoney(amount);
			break;
		}
		catch (const exception & e)
		{
			cout << e.what() << endl;
			break;
		}
	}
	case 3:
	{	
		try
		{
			float amount = GetAmount();
			client->PutMoney(amount);
			break;
		}
		catch (const exception & e)
		{
			cout << e.what() << endl;
			break;
		}
	}
	case 4:
	{
		if (dynamic_cast<IndividualPerson*>(client))
			break;

		if ((*_banks).size() < 1) {
			cout << "Банков нет!" << endl;
			break;
		}

		PrintClients();
		int bankIndex = GetBankIndex();

		int clientsCount = (*_banks)[bankIndex].GetClientsCount();

		if (clientsCount < 1) {
			cout << "Клиентов в банке нет!" << endl;
			break;
		}

		int clientIndex = GetClientIndex(clientsCount);
		try
		{
			float amount = GetAmount();
			static_cast<LegalPerson*>(client)->TransferMoney((*_banks)[bankIndex][clientIndex], amount);
			break;
		}
		catch (const exception & e)
		{
			cout << e.what() << endl;
			break;
		}
	}
	case -1:
		return;
	}
}

float ClientView::GetAmount()
{
	while (true)
	{
		cout << "Введите сумму: ";
		float value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено число!\n";
		}
		else
		{
			return value;
		}
	}
}

void ClientView::PrintClients()
{
	for (int j = 0; j < _banks->size(); j++)
	{
		cout << j + 1 << ". Банк " + (*_banks)[j].GetName() << endl;

		if ((*_banks)[j].GetClientsCount() < 1)
			cout << "\t" << "Клиентов нет!" << endl;

		for (int i = 0; i < (*_banks)[j].GetClientsCount(); i++)
		{
			cout << "\t" << i + 1 << ". ";
			(*_banks)[j][i]->Print();
			cout << endl;
		}
	}
}

int ClientView::GetBankIndex()
{
	while (true)
	{
		cout << "Введите номер банка: ";
		int value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено число!\n";
		}
		else if (value < 1 || value > _banks->size())
		{
			cout << "Введите число в интервале [1; " << _banks->size() << "]";
		}
		else
		{
			return value - 1;
		}
	}
}

int ClientView::GetClientIndex(int size)
{
	while (true)
	{
		cout << "Введите номер клиента: ";
		int value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено число!\n";
		}
		else if (value < 1 || value > size)
		{
			cout << "Введите число в интервале [1; " << size << "]";
		}
		else
		{
			return value - 1;
		}
	}
}
