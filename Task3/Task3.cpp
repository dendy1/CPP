// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
    try
    {
        DoublyLinkedList<int> intList;
        intList.InsertTail(5);
        intList.InsertTail(4);
        intList.InsertTail(3);
        intList.InsertTail(2);
        intList.InsertTail(1);
        std::cout << "Do udalenia: ";
        intList.Print();
        std::cout << std::endl;
        std::cout << "Udalenie 2 (3) elementa: ";
        intList.Remove(2);
        intList.Print();
        std::cout << std::endl;
        std::cout << "Udalenie hvosta: ";
        intList.RemoveTail();
        intList.Print();
        std::cout << std::endl;
        std::cout << "Dobavlenie golovi: ";
        intList.InsertHead(-3);
        intList.Print();
        std::cout << std::endl;
        std::cout << "Dobavlenie hvosta: ";
        intList.InsertTail(-10);
        intList.Print();
        std::cout << std::endl;
        std::cout << "Dobavlenie posle 3 (4) elementa: ";
        intList.InsertAfter(-200, 3);
        intList.Print();

        std::cout << std::endl << "List count: " << intList.GetCount() << std::endl << "List First: " << intList.GetFirst()->value << std::endl << "List Last: " << intList.GetLast()->value << std::endl;

        DoublyLinkedList<char> charList;
        charList.InsertTail('a');
        charList.InsertTail('b');
        charList.InsertTail('c');
        charList.InsertTail('d');
        charList.InsertTail('e');
        std::cout << "Do udalenia: ";
        charList.Print();
        std::cout << std::endl;
        std::cout << "Udalenie 4 (5) elementa: ";
        charList.Remove(4);
        charList.Print();
        std::cout << std::endl;
        std::cout << "Udalenie golovi: ";
        charList.RemoveHead();
        charList.Print();
        std::cout << std::endl;
        std::cout << "Clear: ";
        charList.Clear();
        charList.Print();
    }
    catch (std::exception & e)
    {
        std::cout << std::endl << "ERROR! " << e.what();
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
