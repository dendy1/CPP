#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class DoublyLinkedList
{
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _count;

public:
	DoublyLinkedList() {
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	}

	~DoublyLinkedList() {
		Clear();
	}

	void InsertHead(T value) {
		Node<T>* node = new Node<T>(value);
		node->next = _head;

		// Ћишн€€ проверка
		if (_head != nullptr)
			_head->prev = node;

		if (_count == 0)
			_head = _tail = node;
		else
			_head = node;

		_count++;
	}

	void InsertTail(T value) {
		Node<T>* node = new Node<T>(value);
		node->prev = _tail;

		if (_tail != nullptr)
			_tail->next = node;

		if (_count == 0)
			_tail = _head = node;
		else
			_tail = node;

		_count++;
	}

	void InsertAfter(T data, int position)
	{
		if (position < -1 || position > _count - 1)
			throw std::exception("Index out of range");

		if (position == -1)
			InsertHead(data);
		else if (position == _count - 1)
			InsertTail(data);
		else
		{
			Node<T>* node = new Node<T>(data);

			Node<T>* prev = this->operator[](position);
			Node<T>* next = prev->next;

			prev->next = node;
			node->prev = prev;

			node->next = next;
			next->prev = node;

			_count++;
		}
	}

	void RemoveHead()
	{
		if (_count < 1)
			throw std::exception("List is empty!");

		Node<T>* head = _head;
		if (_count == 1)
		{
			_head = _tail = nullptr;
		}
		else
		{
			_head->next->prev = nullptr;
			_head = _head->next;
		}

		delete[] head;
		_count--;
	}


	void RemoveTail()
	{
		if (_count < 1)
			throw std::exception("List is empty!");

		Node<T>* tail = _tail;

		if (_count == 1)
		{
			_tail = _head = nullptr;
		}
		else
		{
			_tail->prev->next = nullptr;
			_tail = _tail->prev;
		}

		delete[] tail;
		_count--;
	}

	void Remove(int position)
	{
		if (position < 0 || position > _count - 1)
			throw std::exception("Index out of range");

		if (_count < 1)
			throw std::exception("List is empty!");

		if (position == 0)
			RemoveHead();
		else if (position == _count - 1)
			RemoveTail();
		else
		{
			Node<T>* removableNode = this->operator[](position);

			Node<T>* prev = removableNode->prev;
			Node<T>* next = removableNode->next;

			prev->next = removableNode->next;
			next->prev = removableNode->prev;

			delete[] removableNode;

			_count--;
		}

		if (_count == 1)
			_head = _tail = nullptr;
	}

	Node<T>* operator[](const int index)
	{
		if (index < 0 || index > _count - 1)
			throw std::exception("Index out of range");
		//
		if (index == 0)
			return _head;
		if (index == _count - 1)
			return _tail;

		int i = 0;

		Node<T>* tmp = _head;
		while (i++ < index)
			tmp = tmp->next;

		return tmp;
	}

	Node<T>* GetFirst()
	{
		if (_count < 1)
			throw std::exception("List is empty!");
		// возвращать значение
		return _head;
	}

	Node<T>* GetLast()
	{
		if (_count < 1)
			throw std::exception("List is empty!");

		return _tail;
	}
	
	int GetCount()
	{
		return _count;
	}

	void Clear()
	{
		while (_count > 0)
			RemoveHead();
	}

	void Print()
	{
		// tostring
		Node<T>* tmp = _head;
		while (tmp != nullptr)
		{

			std::cout << tmp->value;
			if (tmp != _tail)
			{
				std::cout << "-->";
			}
			tmp = tmp->next;
		}
	}
};

