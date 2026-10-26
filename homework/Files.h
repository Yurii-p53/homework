
#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class File
{
public:

	virtual void Display(const char* path)
	{
		ifstream file(path);

		if (!file.is_open())
		{
			cout << "File not found!" << endl;
			return;
		}

		char c;

		while (file.get(c))
		{
			cout << c;
		}

		file.close();
	}

	virtual ~File() {}
};


class ASCIIFile : public File
{
public:

	virtual void Display(const char* path) override
	{
		ifstream file(path, ios::binary);

		if (!file.is_open())
		{
			cout << "File not found!" << endl;
			return;
		}

		char c;

		while (file.get(c))
		{
			cout << (int)(unsigned char)c << " ";
		}

		file.close();
	}
};


class BinaryFile : public File
{
public:

	virtual void Display(const char* path) override
	{
		ifstream file(path, ios::binary);

		if (!file.is_open())
		{
			cout << "File not found!" << endl;
			return;
		}

		char c;

		while (file.get(c))
		{
			unsigned char b = (unsigned char)c;

			for (int i = 7; i >= 0; i--)
			{
				cout << ((b >> i) & 1);
			}

			cout << " ";
		}

		file.close();
	}
};
