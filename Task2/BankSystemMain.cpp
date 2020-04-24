/* Банковская система.Можно создать несколько банков.В каждом банке может быть несколько клиентов.Клиенты банка могут быть физическими и юридическими лицами.
У каждого клиента банка существут счет(только один).У банка также существует аналогичный параметр – сумма собственных средств банка.Клиенты банка могут проводить операции :
    •	положить деньги на счет;
    •  	снять деньги со счета;
    •	сделать перевод суммы денег на другой счет(возможно в другом банке, только для юридических лиц).
При переводе денег со счета на счет с суммы перевода в пользу банка взимается определенный процент.
Необходимо предусмотреть интерфейс для создания / удаления банков, создания / удаления клиентов каждого банка, 
а также выполнения каждым клиентом перечисленных операций.При этом не должны допускаться операции, в результате которых счет клиента становится отрицательным. */

   
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