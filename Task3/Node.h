#pragma once
template <class T>
class Node
{
public:
	Node* prev;
	Node* next;
	T value;
	
	Node<T>() {
		prev = nullptr;
		next = nullptr;
	}

	Node<T>(T data) : Node<T>() {
		value = data;
	}
};

