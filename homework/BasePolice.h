#pragma once

#include<iostream>

#include"List.h"
#include"BTree.h"

using namespace std;

class Protocol
{
	string number;
	string date;
	int sum;
	bool isPay = false;

public:

	string getNumber()
	{
		return number;
	}

	friend istream& operator>>(istream& in, Protocol& p);
	friend ostream& operator<<(ostream& out, const Protocol& p);
	friend ostream& operator<<(ostream& out, const Protocol* p);
};

istream& operator>>(istream& in, Protocol& p)
{
	cout << "номер: ";
	in >> p.number;

	cout << "дата: ";
	in >> p.date;

	cout << "сумма: ";
	in >> p.sum;

	p.isPay = false;

	return in;
}

ostream& operator<<(ostream& out, const Protocol& p)
{
	out << "дата: " << p.date << endl;
	out << "Штраф: " << p.sum << endl;

	if (p.isPay)
	{
		out << "Оплачено" << endl;
	}
	else
	{
		out << "Не оплачено" << endl;
	}

	return out;
}

ostream& operator<<(ostream& out, const Protocol* p)
{
	if (p != nullptr)
	{
		out << *p;
	}

	return out;
}


class BasePolice
{
	BTree<string, List<Protocol*>> base;

public:

	void addProtocol();

	void print();

	void print(string number);

	void print(string number1, string number2);

	void save();

	void load();

	void pay();
};


void BasePolice::addProtocol()
{
	Protocol* p = new Protocol;

	cin >> *p;

	List<Protocol*>* l = base.getValue(p->getNumber());

	if (l)
	{
		l->push_back(p);
	}
	else
	{
		List<Protocol*> newList;
		newList.push_back(p);
		base.push_r(p->getNumber(), newList);
	}
}


void BasePolice::print()
{
	base.printData();
}


void BasePolice::print(string number)
{
	List<Protocol*>* l = base.getValue(number);

	if (l)
	{
		cout << "Машина: " << number << endl;
		l->print();
	}
	else
	{
		cout << "Не знайдено!" << endl;
	}
}


void BasePolice::print(string number1, string number2)
{
	if (number1 > number2)
	{
		string temp = number1;
		number1 = number2;
		number2 = temp;
	}

	base.printRange(number1, number2);
}