#pragma once
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
class MainView
{
private:
	DoublyLinkedList<T>* _list;

	int getPosition(int border);
	T getValue();

public:
	MainView() 
	{
		_list = new DoublyLinkedList<T>();
	}

	~MainView() 
	{
		delete[] _list;
	}

	void Show() 
	{
		while (true)
		{
			cout << "====Main Menu====" << endl;
			cout << "1. Добавить элемент в начало" << endl;
			cout << "2. Добавить элемент в конец" << endl;
			cout << "3. Добавить элемент на позицию" << endl;

			cout << "4. Удалить элемент из начала" << endl;
			cout << "5. Удалить элемент из конца" << endl;
			cout << "6. Удалить элемент на позиции" << endl;

			cout << "7. GetFirst()" << endl;
			cout << "8. GetLast()" << endl;

			cout << "9. Вывести на экран элемент на позиции" << endl;
			cout << "10. Вывести на экран весь список" << endl;

			cout << "11. Очистить список" << endl;

			cout << "-1. Выход (введите -1)" << endl;
			cout << "Ваш выбор: ";

			int opt;
			cin >> opt;
			cout << "=================" << endl;

			T value;
			int pos;
			try
			{
				switch (opt)
				{
				case 1:
					value = getValue();
					_list->InsertHead(value);
					break;
				case 2:
					value = getValue();
					_list->InsertTail(value);
					break;
				case 3:
					value = getValue();
					pos = getPosition(_list->GetCount());
					_list->InsertPosition(value, pos);
					break;
				case 4:
					_list->RemoveHead();
					break;
				case 5:
					_list->RemoveTail();
					break;
				case 6:
					pos = getPosition(_list->GetCount() - 1);
					_list->RemovePosition(pos);
					break;
				case 7:
					cout << _list->GetFirst() << endl;
					break;
				case 8:
					cout << _list->GetLast() << endl;
					break;
				case 9:
					pos = getPosition(_list->GetCount() - 1);
					cout << (*_list)[pos] << endl;
					break;
				case 10:
					cout << _list->ToString() << endl;
					break;
				case 11:
					_list->Clear();
					break;
				case -1:
					return;
				}
			}
			catch (const exception & e)
			{
				cout << e.what() << endl;
			}
		}
	}
};

template<class T>
inline int MainView<T>::getPosition(int border)
{
	while (true)
	{
		cout << "Введите позицию: ";
		int value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено число!\n";
		}
		else if (value < 0 || value > border)
		{
			cout << "Введите число в интервале [0, " << border << "]";
		}
		else
		{
			return value;
		}
	}
}

template<class T>
inline T MainView<T>::getValue()
{
	while (true)
	{
		cout << "Введите значение: ";
		T value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверно введено значение!\n";
		}
		else
		{
			return value;
		}
	}
}
