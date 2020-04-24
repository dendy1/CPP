#pragma once
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Client;
class IndividualPerson;
class LegalPerson;

class Bank
{
	public:
		Bank(string name, float startAccount, float transferPercentage);
		~Bank();

		void AddClient(Client* client);
		void AddClient(string firstName, string secondName, int type);
		void RemoveClient(int index);

		int GetClientsCount();

		string GetName();
		float GetAccount();
		float GetTransferPercentage();

		Client* GetClient(int index);
		Client*& operator[] (const int index);

		void OnClientPut(float amount);
		void OnClientWidthdraw(float amount);
		void OnClientTransfer(float amount);
		float CalculateTransfer(float amount);

		void Print();

	private:
		float _account;
		float _transferPercentage;
		string _name;
		std::vector<Client*> _clients;
};
