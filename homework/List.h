#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class Node
{
public:
	T value;
	Node<T>* next;
	Node<T>* prev;

	Node(T value)
	{
		this->value = value;
		next = nullptr;
		prev = nullptr;
	}
};

template<class T>
class List
{
	Node<T>* first;
	Node<T>* last;
	size_t size;

public:
	List()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	~List()
	{
		clear();
	}

	void push_back(T value)
	{
		Node<T>* temp = new Node<T>(value);

		if (first == nullptr)
		{
			first = temp;
			last = temp;
		}
		else
		{
			last->next = temp;
			temp->prev = last;
			last = temp;
		}

		size++;
	}

	void push_front(T value)
	{
		Node<T>* temp = new Node<T>(value);

		if (first == nullptr)
		{
			first = temp;
			last = temp;
		}
		else
		{
			temp->next = first;
			first->prev = temp;
			first = temp;
		}

		size++;
	}

	void insert(size_t index, T value)
	{
		if (index == 0)
		{
			push_front(value);
			return;
		}

		if (index >= size)
		{
			push_back(value);
			return;
		}

		Node<T>* temp = first;

		for (int i = 0; i < index; i++)
			temp = temp->next;

		Node<T>* node = new Node<T>(value);

		node->next = temp;
		node->prev = temp->prev;
		temp->prev->next = node;
		temp->prev = node;

		size++;
	}

	void remove(T value)
	{
		Node<T>* temp = first;

		while (temp != nullptr)
		{
			if (temp->value == value)
			{
				if (temp == first)
					first = temp->next;
				else
					temp->prev->next = temp->next;

				if (temp == last)
					last = temp->prev;
				else
					temp->next->prev = temp->prev;

				delete temp;
				size--;
				return;
			}

			temp = temp->next;
		}
	}

	void erase(size_t index)
	{
		if (index >= size)
			return;

		Node<T>* temp = first;

		for (int i = 0; i < index; i++)
			temp = temp->next;

		if (temp == first)
			first = temp->next;
		else
			temp->prev->next = temp->next;

		if (temp == last)
			last = temp->prev;
		else
			temp->next->prev = temp->prev;

		delete temp;
		size--;
	}

	int firstIndex(T value) const
	{
		Node<T>* temp = first;
		int index = 0;

		while (temp != nullptr)
		{
			if (temp->value == value)
				return index;

			temp = temp->next;
			index++;
		}

		return -1;
	}

	int lastIndex(T value) const
	{
		Node<T>* temp = last;
		int index = size - 1;

		while (temp != nullptr)
		{
			if (temp->value == value)
				return index;

			temp = temp->prev;
			index--;
		}

		return -1;
	}

	T getRandom()
	{
		if (size == 0)
			return T();

		int number = rand() % size;
		Node<T>* temp = first;

		for (int i = 0; i < number; i++)
			temp = temp->next;

		return temp->value;
	}

	T& operator[](size_t index)
	{
		Node<T>* temp = first;

		for (int i = 0; i < index && temp != nullptr; i++)
			temp = temp->next;

		return temp->value;
	}

	List<T> operator+(const List<T>& obj)
	{
		List<T> result;

		Node<T>* temp = first;

		while (temp != nullptr)
		{
			result.push_back(temp->value);
			temp = temp->next;
		}

		temp = obj.first;

		while (temp != nullptr)
		{
			result.push_back(temp->value);
			temp = temp->next;
		}

		return result;
	}

	bool empty() const
	{
		return first == nullptr;
	}

	size_t getSize() const
	{
		return size;
	}

	void print() const
	{
		Node<T>* temp = first;

		while (temp != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}

		cout << endl;
	}

	void clear()
	{
		Node<T>* temp = first;

		while (temp != nullptr)
		{
			Node<T>* next = temp->next;
			delete temp;
			temp = next;
		}

		first = nullptr;
		last = nullptr;
		size = 0;
	}
};