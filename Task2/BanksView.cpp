#include "BanksView.h"

string BanksView::GetBankName()
{
	while (true)
	{
		cout << "Введите имя банка: ";
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

float BanksView::GetStartAccount()
{
	while (true)
	{
		cout << "Введите стартовый баланс банка: ";
		float value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено число!\n";
		}
		else if (value < 0)
		{
			cout << "Введите неотрицательное число" << endl;
		}
		else
		{
			return value;
		}
	}
}

float BanksView::GetTransferPercentage()
{
	while (true)
	{
		cout << "Введите процент перевода банка [0, 100]: ";
		float value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено число!\n";
		}
		else if (value < 0 || value > 100)
		{
			cout << "Введите число в интервале [0; 100]" << endl;
		}
		else
		{
			return value;
		}
	}
}

BanksView::BanksView()
{
	_banks = &(vector<Bank>());
	_bankView = BankView(_banks);
}

BanksView::BanksView(vector<Bank>* banks)
{
	_banks = banks;
	_bankView = BankView(_banks);
}

BanksView::~BanksView()
{

}

void BanksView::PrintBanks()
{
	for (int i = 0; i < _banks->size(); i++)
	{
		cout << i + 1 << ". ";
		(*_banks)[i].Print();
		cout << endl;
	}
}

int BanksView::GetBankIndex()
{
	while (true)
	{
		cout << "Введите номер банка: ";
		unsigned int value;
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

void BanksView::Show()
{
	while (true)
	{
		cout << "====Banks Menu====" << endl;
		cout << "1. Показать банки (введите 1)" << endl;
		cout << "2. Перейти в меню конкретного банка (введите 2)" << endl;
		cout << "3. Добавить банк (введите 3)" << endl;
		cout << "4. Удалить банк (введите 4)" << endl;
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

			PrintBanks();
			break;
		}
		case 2:
		{
			if (_banks->size() < 1) {
				cout << "Банков нет!" << endl;
				break;
			}

			PrintBanks();
			int bankIndex = GetBankIndex();
			_bankView.Show(&(*_banks)[bankIndex]);
			break;
		}
		case 3:
		{
			string name = GetBankName();
			float startAccount = GetStartAccount();
			float transferPercentage = GetTransferPercentage();
			(*_banks).push_back(Bank(name, startAccount, transferPercentage));
			break;
		}
		case 4:
		{
			if (_banks->size() < 1) {
				cout << "Банков нет!" << endl;
				break;
			}

			PrintBanks();
			int bankIndex = GetBankIndex();
			_banks->erase(_banks->begin() + bankIndex);
			break;
		}
		case -1:
			return;
		}
	}
}
