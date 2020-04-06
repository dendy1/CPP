#include "BankView.h"

BankView::BankView()
{
}

BankView::BankView(vector<Bank>* banks)
{
	_clientView = ClientView(banks);
}

BankView::~BankView()
{

}

void BankView::Show(Bank* bank)
{
	while (true)
	{
		cout << "====" << bank->GetName() << " bank menu" << "====" << endl;
		cout << "1. Полная информация о банке (введите 1)" << endl;
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
			bank->Print();
			break;
		}
		case 2:
		{
			if (bank->GetClientsCount() < 1)
			{
				cout << "Клиентов в банке нет!" << endl;
				break;
			}

			PrintClients(bank);
			int index = GetClientIndex(bank->GetClientsCount());
			_clientView.Show((*bank)[index]);
			break;
		}
		case 3:
		{
			string firstname = GetClientInfo("имя");
			string secondname = GetClientInfo("фамилию");
			int type = GetClientType();
			bank->AddClient(firstname, secondname, type);
			break;
		}
		case 4:
		{
			if (bank->GetClientsCount() < 1)
			{
				cout << "Клиентов в банке нет!" << endl;
				break;
			}

			PrintClients(bank);
			int index = GetClientIndex(bank->GetClientsCount());
			bank->RemoveClient(index);
			break;
		}
		case -1:
			return;
		}
	}
}

void BankView::PrintClients(Bank* bank)
{
	if (bank->GetClientsCount() < 1)
	{
		cout << "Клиентов в банке нет!" << endl;
		return;
	}

	for (int i = 0; i < bank->GetClientsCount(); i++)
	{
		cout << i + 1 << ". ";
		(*bank)[i]->Print();
		cout << endl;
	}
}

int BankView::GetClientIndex(int size)
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

int BankView::GetClientType()
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

std::string BankView::GetClientInfo(string placeholder)
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
