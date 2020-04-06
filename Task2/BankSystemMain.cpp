// BankSystem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
   
#include <iostream>
#include "Bank.h"
#include "MainView.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<Bank> bankSystem;
    Bank sberbank = Bank("Sberbank", 10000, 20);
    sberbank.AddClient("andrei", "borodin", 1);
    sberbank.AddClient("dmitri", "petrov", 2);
    sberbank.AddClient("ilia", "korobkin", 1);

    Bank alphabank = Bank("Alphabank", 5000, 10);
    alphabank.AddClient("vasya", "pupkin", 1);
    alphabank.AddClient("vova", "pupikin", 2);

    bankSystem.push_back(alphabank);
    bankSystem.push_back(sberbank);

    MainView mainView = MainView(&bankSystem);
    try
    {
        mainView.Show();
    }
    catch (const exception & e)
    {
        cout << e.what();
    }
}