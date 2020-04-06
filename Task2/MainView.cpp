#include "MainView.h"

MainView::MainView()
{
	_banksView = BanksView();
	_clientsView = ClientsView();
}

MainView::MainView(vector<Bank>* banks)
{
	_banksView = BanksView(banks);
	_clientsView = ClientsView(banks);
}

MainView::~MainView()
{
	delete& _banksView;
	delete& _clientsView;
}

void MainView::Show()
{
	while (true)
	{
		cout << "====Main Menu====" << endl;
		cout << "1. Меню банков (введите 1)" << endl;
		cout << "2. Меню клиентов (введите 2)" << endl;
		cout << "-1. Выход (введите -1)" << endl;
		cout << "Ваш выбор: ";

        int opt;
        cin >> opt;

		cout << "=================" << endl;
        switch (opt)
        {
		case 1:
			_banksView.Show();
			break;
		case 2:
			_clientsView.Show();
			break;
		case -1:
			exit(1);
			break;
        }
	}
}
