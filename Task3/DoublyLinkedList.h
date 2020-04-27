#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

template <class T>
class DoublyLinkedList
{
private:
	Node<T>* _head;
	Node<T>* _tail;
	int _count;

	void setItem(int index, T value) 
	{ 
		if (index < 0 || index > _count - 1)
			throw std::exception("Index out of range");

		int i = 0;

		Node<T>* tmp = _head;
		while (i++ < index)
			tmp = tmp->next;

		tmp->value = value;
	}

	Node<T>* getItem(const int index) 
	{ 
		if (index < 0 || index > _count - 1)
			throw std::exception("Index out of range");

		int i = 0;

		Node<T>* tmp = _head;
		while (i++ < index)
			tmp = tmp->next;

		return tmp;
	}

public:
	DoublyLinkedList() 
	{
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	}

	~DoublyLinkedList() 
	{
		Clear();
	}

	void InsertHead(T value) 
	{
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

	void InsertTail(T value) 
	{
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

	void InsertPosition(T data, int position)
	{
		if (position < 0 || position > _count)
			throw std::exception("Index out of range");

		if (position == 0)
			InsertHead(data);
		else if (position == _count)
			InsertTail(data);
		else
		{
			Node<T>* node = new Node<T>(data);

			Node<T>* prev = getItem(position - 1);
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

	void RemovePosition(int position)
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
			Node<T>* removableNode = getItem(position);

			Node<T>* prev = removableNode->prev;
			Node<T>* next = removableNode->next;

			prev->next = removableNode->next;
			next->prev = removableNode->prev;

			delete[] removableNode;

			_count--;
		}

		if (_count == 0)
			_head = _tail = nullptr;
	}

	T operator[](const int index)
	{
		if (index < 0 || index > _count - 1)
			throw std::exception("Index out of range");

		int i = 0;

		Node<T>* tmp = _head;
		while (i++ < index)
			tmp = tmp->next;

		return tmp->value;
	}

	T GetFirst()
	{
		if (_count < 1)
			throw std::exception("List is empty!");

		return _head->value;
	}

	T GetLast()
	{
		if (_count < 1)
			throw std::exception("List is empty!");

		return _tail->value;
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

	std::string ToString()
	{
		std::stringstream ss;

		Node<T>* tmp = _head;
		while (tmp != nullptr)
		{
			ss << tmp->value;
			if (tmp != _tail)
			{
				ss << "-->";
			}
			tmp = tmp->next;
		}


		return ss.str();
	}
};

