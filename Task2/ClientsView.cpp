#include "ClientsView.h"
#include "Bank.h"
#include "Client.h"

ClientsView::ClientsView()
{
	_banks = &(vector<Bank>());
	_clientView = ClientView(_banks);
}

ClientsView::ClientsView(vector<Bank>* banks)
{
	_banks = banks;
	_clientView = ClientView(_banks);
}

ClientsView::~ClientsView()
{

}

void ClientsView::PrintClients()
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

int ClientsView::GetBankIndex()
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

int ClientsView::GetClientIndex(int size)
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

int ClientsView::GetClientType()
{
	while (true)
	{
		cout << "Введите тип клиента (1 - физическое лицо, 2 - юридическое лицо): ";
		int value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено число!\n";
		}
		else if (value < 1 || value > 2)
		{
			cout << "Введите число 1 или 2!\n";
		}
		else 
		{
			return value;
		}
	}
}

std::vector<Client*> ClientsView::GetAllClients()
{
	std::vector<Client*> clients;
	for (Bank bank : *_banks) {
		for (int i = 0; i < bank.GetClientsCount(); i++)
		{
			clients.push_back(bank[i]);
		}
	}

	return clients;
}

std::string ClientsView::GetClientInfo(string placeholder)
{
	while (true)
	{
		cout << "Введите " << placeholder << " клиента:";
		string value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено имя!\n";
		}
		else
		{
			return value;
		}
	}
}

void ClientsView::Show()
{
	while (true)
	{
		cout << "====Clients Menu====" << endl;
		cout << "1. Показать клиентов (введите 1)" << endl;
		cout << "2. Перейти в меню конкретного клиента (введите 2)" << endl;
		cout << "3. Добавить клиента (введите 3)" << endl;
		cout << "4. Удалить клиента (введите 4)" << endl;
		cout << "-1. Выход (введите -1)" << endl;
		cout << "Ваш выбор: ";

		int opt;
		cin >> opt;

		cout << "=================" << endl;
		switch (opt)
		{
		case 1:
		{
			if (_banks->size() < 1) {
				cout << "Банков нет!" << endl;
				break;
			}

			PrintClients();
			break;
		}
		case 2:
		{
			if (_banks->size() < 1) {
				cout << "Банков нет!" << endl;
				break;
			}

			PrintClients();
			int bankIndex = GetBankIndex();

			if ((*_banks)[bankIndex].GetClientsCount() < 1)
			{
				cout << "Клиентов нет!" << endl;
				break;
			}
				
			int clientsCount = (*_banks)[bankIndex].GetClientsCount();

			if (clientsCount < 1) {
				cout << "Клиентов в банке нет!" << endl;
				break;
			}

			int clientIndex = GetClientIndex(clientsCount);
			_clientView.Show((*_banks)[bankIndex][clientIndex]);
			break;
		}
		case 3:
		{
			if (_banks->size() < 1) {
				cout << "Банков нет!" << endl;
				break;
			}

			PrintClients();
			int bankIndex = GetBankIndex();

			string firstname = GetClientInfo("имя");
			string secondname = GetClientInfo("фамилию");
			int type = GetClientType();

			(*_banks)[bankIndex].AddClient(firstname, secondname, type);
			break;
		}
		case 4:
		{
			if (_banks->size() < 1) {
				cout << "Банков нет!" << endl;
				break;
			}

			PrintClients();
			int bankIndex = GetBankIndex();

			if ((*_banks)[bankIndex].GetClientsCount() < 1)
			{
				cout << "Клиентов нет!" << endl;
				break;
			}

			int clientsCount = (*_banks)[bankIndex].GetClientsCount();

			if (clientsCount < 1) {
				cout << "Клиентов в банке нет!" << endl;
				break;
			}

			int clientIndex = GetClientIndex(clientsCount);
			(*_banks)[bankIndex].RemoveClient(clientIndex);
			break;

		}
		case -1:
			return;
		}
	}
}
