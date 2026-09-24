#pragma once

#include <iostream>

#include "String.h"

using namespace std;

class Book
{
	String author;
	String title;
	String publisher;
	int year;
	int quantity;
	int pages;

public:

	Book() : author("None"), title("None"), publisher("None"), year(0), quantity(0), pages(0)
	{
		cout << "Default constructor Book" << endl;
	}

	explicit Book(const char* title) : author("None"), title(title), publisher("None"), year(0), quantity(0), pages(0)
	{
		cout << "Explicit constructor Book" << endl;
	}

	Book(const char* author, const char* title, const char* publisher, int year, int quantity, int pages): author(author), title(title), publisher(publisher), year(year), quantity(quantity), pages(pages)
	{
		cout << "Parameterized constructor Book" << endl;
	}

	Book(const Book& obj): author(obj.author),title(obj.title),publisher(obj.publisher),year(obj.year),quantity(obj.quantity),pages(obj.pages)
	{
		cout << "Copy constructor Book" << endl;
	}

	Book& operator=(const Book& obj)
	{
		if (this == &obj)
		{
			return *this;
		}

		author = obj.author;
		title = obj.title;
		publisher = obj.publisher;
		year = obj.year;
		quantity = obj.quantity;
		pages = obj.pages;

		return *this;
	}

	void setA(const String& author)
	{
		this->author = author;
	}

	void setT(const String& title)
	{
		this->title = title;
	}

	void setP(const String& publisher)
	{
		this->publisher = publisher;
	}

	void setY(int year)
	{
		this->year = year;
	}

	void setQ(int quantity)
	{
		this->quantity = quantity;
	}

	void setPg(int pages)
	{
		this->pages = pages;
	}

	const String& getA() const
	{
		return author;
	}

	const String& getT() const
	{
		return title;
	}

	const String& getP() const
	{
		return publisher;
	}

	int getY() const
	{
		return year;
	}

	int getQ() const
	{
		return quantity;
	}

	int getPg() const
	{
		return pages;
	}

	void print() const
	{
		cout << "------------------------" << endl;

		cout << "Author: ";
		author.print();

		cout << "Title: ";
		title.print();

		cout << "Publisher: ";
		publisher.print();

		cout << "Year: " << year << endl;
		cout << "Quantity: " << quantity << endl;
		cout << "Pages: " << pages << endl;

		cout << "------------------------" << endl;
	}
};
