#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include"String.h"
#include"Book.h"

using namespace std;

int main()
{
	Book books[5] =
	{
		Book("George Orwell", "1984", "Penguin Books", 1949, 10, 328),
		Book("J. K. Rowling", "Harry Potter", "Bloomsbury", 1997, 15, 352),
		Book("George Orwell", "Animal Farm", "Penguin Books", 1945, 8, 112),
		Book("Stephen King", "The Shining", "Doubleday", 1977, 12, 447),
		Book("J. K. Rowling", "Fantastic Beasts", "Bloomsbury", 2001, 7, 128)
	};


	cout << "books:" << endl;

	for (int i = 0; i < 5; i++)
	{
		books[i].print();
	}


	cout << endl;

	const char* a = "george Orwell";

	for (int i = 0; i < 5; i++)
	{
		if (strcmp(books[i].getA().get(), a) == 0)
		{
			books[i].print();
		}
	}


	cout << endl;

	const char* p = "bloomsbury";

	for (int i = 0; i < 5; i++)
	{
		if (strcmp(books[i].getP().get(), p) == 0)
		{
			books[i].print();
		}
	}


	cout << endl;

	int y = 1990;

	for (int i = 0; i < 5; i++)
	{
		if (books[i].getY() > y)
		{
			books[i].print();
		}
	}


	cout << endl;

	Book b1("None");

	b1.print();


	return 0;
}
