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
		cout << "1. ������ ���������� � ����� (������� 1)" << endl;
		cout << "2. ������� � ���� ����������� ������� (������� 2)" << endl;
		cout << "3. �������� ������� (������� 3)" << endl;
		cout << "4. ������� ������� (������� 4)" << endl;
		cout << "-1. ����� (������� -1)" << endl;		
		cout << "��� �����: ";

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
				cout << "�������� � ����� ���!" << endl;
				break;
			}

			PrintClients(bank);
			int index = GetClientIndex(bank->GetClientsCount());
			_clientView.Show((*bank)[index]);
			break;
		}
		case 3:
		{
			string firstname = GetClientInfo("���");
			string secondname = GetClientInfo("�������");
			int type = GetClientType();
			bank->AddClient(firstname, secondname, type);
			break;
		}
		case 4:
		{
			if (bank->GetClientsCount() < 1)
			{
				cout << "�������� � ����� ���!" << endl;
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
		cout << "�������� � ����� ���!" << endl;
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
		cout << "������� ����� �������: ";
		int value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ������� �����!\n";
		}
		else if (value < 1 || value > size)
		{
			cout << "������� ����� � ��������� [1; " << size << "]";
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
		cout << "������� ��� ������� (1 - ���������� ����, 2 - ����������� ����): ";
		int value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ������� �����!\n";
		}
		else if (value < 1 || value > 2)
		{
			cout << "������� ����� 1 ��� 2!\n";
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
		cout << "������� " << placeholder << " �������:";
		string value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������� ������� ���!\n";
		}
		else
		{
			return value;
		}
	}
}
