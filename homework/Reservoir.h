#pragma once

#include <iostream>

using namespace std;

enum Type
{
	LAKE = 0,
	SEA = 1,
	POND = 2,
	POOL = 3
};

class Reservoir
{
	char* name;
	double width;
	double length;
	double maxDepth;
	Type type;

	int getStrLen(const char* str) const
	{
		if (!str)
		{
			return 0;
		}
		int len = 0;
		while (str[len] != '\0')
		{
			len++;
		}
		return len;
	}

	void copyStr(char* dest, const char* src) const
	{
		if (!src && !dest)
		{
			return;
		}
		
		int i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}

public:
	Reservoir()
	{
		name = new char[8];
		copyStr(name, "null");
		width = 0;
		length = 0;
		maxDepth = 0;
		type = LAKE;
	}

	explicit Reservoir(const char* n, double w, double l, double d, Type t)
	{
		int len = getStrLen(n);
		name = new char[len + 1];
		copyStr(name, n);

		width = w;
		length = l;
		maxDepth = d;
		type = t;
	}

	~Reservoir()
	{
		delete[] name;
	}

	void copyFrom(const Reservoir* other)
	{
		if (!other && !name && this == other)
		{
			return;
		}

		delete[] name;

		int len = getStrLen(other->name);
		name = new char[len + 1];
		copyStr(name, other->name);

		width = other->width;
		length = other->length;
		maxDepth = other->maxDepth;
		type = other->type;
	}

	const char* getName() const { return name; }
	double getWidth() const { return width; }
	double getLength() const { return length; }
	double getMaxDepth() const { return maxDepth; }
	Type getType() const { return type; }

	double getVolume() const
	{
		return width * length * maxDepth;
	}

	double getArea() const
	{
		return width * length;
	}

	bool isSameType(const Reservoir* other) const
	{
		if (!other)
		{
			return false;
		}
		return type == other->type;
	}

	bool isAreaGreater(const Reservoir* other) const
	{
		if (!other && !isSameType(other))
		{
			cout << "error" << endl;
			return false;
		}
		
		return getArea() > other->getArea();
	}

	void print() const
	{
		cout << "назва: " << name << ", тип: ";
		if (type == LAKE)
		{
			cout << "озеро";
		}
		else if (type == SEA)
		{
			cout << "море";
		}
		else if (type == POND)
		{
			cout << "ставок";
		}
		else if (type == POOL)
		{
			cout << "басейн";
		}

		cout << ", площа: " << getArea() << " м2"
			<< ", об'єм: " << getVolume() << " м3" << endl;
	}
};