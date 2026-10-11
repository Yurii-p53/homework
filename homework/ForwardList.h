
#pragma once

#include <initializer_list>
#include <iostream>

#include "Node.h"

using namespace std;


template<class T>
class ForwardList
{
	Node<T>* first;
	Node<T>* last;
	size_t   size;

	Node<T>* getNode(size_t index) const;


public:
	ForwardList();
	ForwardList(initializer_list<T> list);
	ForwardList(const ForwardList& obj);
	ForwardList<T>& operator=(const ForwardList& obj);
	~ForwardList();

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, size_t index);

	void pop_front();
	void pop_back();
	void remove(size_t index);

	T& front() const;
	T& back() const;
	T at(size_t index) const;
	T& operator[](int index) const;

	ForwardList<T> operator+(const ForwardList<T>& list) const;
	void operator+=(const ForwardList<T>& list);

	void print();
	void clear();
	size_t getSize() const;

	size_t firstIndex(const T& value);
	size_t lastIndex(const T& value);

	int count(const T& value);
	int count_if(bool(*predicate)(const T& value));
};


template<class T>
Node<T>* ForwardList<T>::getNode(size_t index) const
{
	Node<T>* temp = first;

	for (size_t i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp;
}

template<class T>
ForwardList<T>::ForwardList()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

template<class T>
ForwardList<T>::ForwardList(initializer_list<T> list)
{
	first = nullptr;
	last = nullptr;
	size = 0;

	for (T elem : list)
	{
		push_back(elem);
	}
}

template<class T>
ForwardList<T>::ForwardList(const ForwardList& obj)
{
	first = nullptr;
	last = nullptr;
	size = 0;

	Node<T>* temp = obj.first;

	while (temp != nullptr)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& obj)
{
	if (this != &obj)
	{
		clear();

		Node<T>* temp = obj.first;

		while (temp != nullptr)
		{
			push_back(temp->value);
			temp = temp->next;
		}
	}

	return *this;
}

template<class T>
ForwardList<T>::~ForwardList()
{
	clear();
}

template<class T>
void ForwardList<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}

	size++;
}

template<class T>
void ForwardList<T>::push_back(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}

	size++;
}

template<class T>
void ForwardList<T>::insert(const T& value, size_t index)
{
	if (index > size)
	{
		return;
	}

	if (index == 0)
	{
		push_front(value);
	}
	else if (index == size)
	{
		push_back(value);
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* newNode = new Node<T>(value);

		newNode->next = pos->next;
		pos->next = newNode;

		size++;
	}
}

template<class T>
void ForwardList<T>::pop_front()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;

		delete temp;
		size--;

		if (size == 0)
		{
			last = nullptr;
		}
	}
}

template<class T>
void ForwardList<T>::pop_back()
{
	if (size > 0)
	{
		if (size == 1)
		{
			delete first;
			first = nullptr;
			last = nullptr;
		}
		else
		{
			Node<T>* temp = getNode(size - 2);

			delete last;
			last = temp;
			last->next = nullptr;
		}

		size--;
	}
}

template<class T>
void ForwardList<T>::remove(size_t index)
{
	if (index >= size)
	{
		return;
	}

	if (index == 0)
	{
		pop_front();
	}
	else if (index == size - 1)
	{
		pop_back();
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* temp = pos->next;

		pos->next = temp->next;

		delete temp;
		size--;
	}
}

template<class T>
T& ForwardList<T>::front() const
{
	return first->value;
}

template<class T>
T& ForwardList<T>::back() const
{
	return last->value;
}

template<class T>
T ForwardList<T>::at(size_t index) const
{
	return getNode(index)->value;
}

template<class T>
T& ForwardList<T>::operator[](int index) const
{
	return getNode(index)->value;
}

template<class T>
ForwardList<T> ForwardList<T>::operator+(const ForwardList<T>& list) const
{
	ForwardList<T> res(*this);
	res += list;

	return res;
}

template<class T>
void ForwardList<T>::operator+=(const ForwardList<T>& list)
{
	Node<T>* temp = list.first;

	while (temp != nullptr)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

template<class T>
void ForwardList<T>::print()
{
	Node<T>* temp = first;

	while (temp != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}

	cout << endl;
}

template<class T>
void ForwardList<T>::clear()
{
	while (size > 0)
	{
		pop_front();
	}
}

template<class T>
size_t ForwardList<T>::getSize() const
{
	return size;
}

template<class T>
size_t ForwardList<T>::firstIndex(const T& value)
{
	Node<T>* temp = first;
	size_t index = 0;

	while (temp != nullptr)
	{
		if (temp->value == value)
		{
			return index;
		}

		temp = temp->next;
		index++;
	}

	return -1;
}

template<class T>
size_t ForwardList<T>::lastIndex(const T& value)
{
	Node<T>* temp = first;
	size_t index = 0;
	size_t foundIndex = -1;

	while (temp != nullptr)
	{
		if (temp->value == value)
		{
			foundIndex = index;
		}

		temp = temp->next;
		index++;
	}

	return foundIndex;
}

template<class T>
int ForwardList<T>::count(const T& value)
{
	Node<T>* temp = first;
	int count = 0;

	while (temp != nullptr)
	{
		if (temp->value == value)
		{
			count++;
		}

		temp = temp->next;
	}

	return count;
}

template<class T>
int ForwardList<T>::count_if(bool(*predicate)(const T& value))
{
	Node<T>* temp = first;
	int count = 0;

	while (temp != nullptr)
	{
		if (predicate(temp->value))
		{
			count++;
		}

		temp = temp->next;
	}

	return count;
}