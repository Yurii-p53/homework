#pragma once
#include <iostream>
#include "Array.h"
#include "String.h"

using namespace std;

enum Type { INT, DOUBLE, STR };

class var
{
	Type type;
	int intVal;
	double dblVal;
	String strVal;

	int length(const String& str) const
	{
		int size = 0;
		while (str[size] != '\0')
		{
			size++;
		}
		return size;
	}

	int toIntVal(const String& str) const
	{
		int result = 0;
		int sign = 1;
		int idx = 0;

		if (str[0] == '-')
		{
			sign = -1;
			idx++;
		}
		while (str[idx] >= '0' && str[idx] <= '9')
		{
			result = result * 10 + (str[idx++] - '0');
		}
		return result * sign;
	}

	double toDblVal(const String& str) const
	{
		double result = 0;
		double frac = 0.1;
		int sign = 1;
		int idx = 0;

		if (str[0] == '-')
		{
			sign = -1;
			idx++;
		}
		while (str[idx] >= '0' && str[idx] <= '9')
		{
			result = result * 10 + (str[idx++] - '0');
		}
		if (str[idx] == '.')
		{
			idx++;
			while (str[idx] >= '0' && str[idx] <= '9')
			{
				result += (str[idx++] - '0') * frac;
				frac *= 0.1;
			}
		}
		return result * sign;
	}

	String intToStr(int num) const
	{
		char buffer[50];
		if (num == 0) return String("0");

		int idx = 0;
		bool isNeg = num < 0;
		if (isNeg) num = -num;

		while (num > 0)
		{
			buffer[idx++] = '0' + num % 10;
			num /= 10;
		}
		if (isNeg) buffer[idx++] = '-';
		buffer[idx] = '\0';

		for (int j = 0; j < idx / 2; j++)
		{
			swap(buffer[j], buffer[idx - j - 1]);
		}
		return String(buffer);
	}

	String dblToStr(double num) const
	{
		char buffer[100];
		int pos = 0;

		if (num < 0)
		{
			buffer[pos++] = '-';
			num = -num;
		}

		int intPart = (int)num;
		double fracPart = num - intPart;

		String intStr = intToStr(intPart);
		for (int i = 0; intStr[i] != '\0'; i++)
		{
			buffer[pos++] = intStr[i];
		}

		if (fracPart != 0)
		{
			buffer[pos++] = '.';
			for (int i = 0; i < 6; i++)
			{
				fracPart *= 10;
				int digit = (int)fracPart;
				buffer[pos++] = '0' + digit;
				fracPart -= digit;
				if (fracPart == 0) break;
			}
			while (pos > 0 && buffer[pos - 1] == '0') pos--;
			if (buffer[pos - 1] == '.') pos--;
		}
		buffer[pos] = '\0';
		return String(buffer);
	}

	int getInt() const
	{
		return (type == INT) ? intVal : ((type == DOUBLE) ? (int)dblVal : toIntVal(strVal));
	}

	double getDbl() const
	{
		return (type == INT) ? (double)intVal : ((type == DOUBLE) ? dblVal : toDblVal(strVal));
	}

	String getStr() const
	{
		return (type == STR) ? strVal : ((type == INT) ? intToStr(intVal) : dblToStr(dblVal));
	}

	bool equalStr(const String& first, const String& second) const
	{
		int len1 = length(first);
		if (len1 != length(second)) return false;

		for (int i = 0; i < len1; i++)
		{
			if (first[i] != second[i]) return false;
		}
		return true;
	}

	bool isLessStr(const String& first, const String& second) const
	{
		int len1 = length(first);
		int len2 = length(second);
		int minLen = (len1 < len2) ? len1 : len2;

		for (int i = 0; i < minLen; i++)
		{
			if (first[i] < second[i]) return true;
			if (first[i] > second[i]) return false;
		}
		return len1 < len2;
	}

public:

	var() : type(INT), intVal(0), dblVal(0.0), strVal("") {}

	var(int value) : type(INT), intVal(value), dblVal(0.0), strVal("") {}

	var(double value) : type(DOUBLE), intVal(0), dblVal(value), strVal("") {}

	var(const char* value) : type(STR), intVal(0), dblVal(0.0), strVal(value) {}

	var(const String& value) : type(STR), intVal(0), dblVal(0.0), strVal(value) {}

	var operator+(const var& obj) const
	{
		if (type == INT) return var(intVal + obj.getInt());
		if (type == DOUBLE) return var(dblVal + obj.getDbl());

		String second = obj.getStr();
		int len1 = length(strVal);
		int len2 = length(second);

		char* buffer = new char[len1 + len2 + 1];
		int idx = 0;

		for (int i = 0; i < len1; i++) buffer[idx++] = strVal[i];
		for (int i = 0; i < len2; i++) buffer[idx++] = second[i];
		buffer[idx] = '\0';

		var result(buffer);
		delete[] buffer;
		return result;
	}

	var operator-(const var& obj) const
	{
		if (type == INT) return var(intVal - obj.getInt());
		if (type == DOUBLE) return var(dblVal - obj.getDbl());

		String second = obj.getStr();
		int len1 = length(strVal);
		int len2 = length(second);

		char* buffer = new char[len1 + 1];
		int idx = 0;

		for (int i = 0; i < len1; i++)
		{
			bool isFound = false;
			for (int j = 0; j < len2; j++)
			{
				if (strVal[i] == second[j])
				{
					isFound = true;
					break;
				}
			}
			if (!isFound) buffer[idx++] = strVal[i];
		}
		buffer[idx] = '\0';

		var result(buffer);
		delete[] buffer;
		return result;
	}

	var operator*(const var& obj) const
	{
		if (type == INT) return var(intVal * obj.getInt());
		if (type == DOUBLE) return var(dblVal * obj.getDbl());

		String second = obj.getStr();
		int len1 = length(strVal);
		int len2 = length(second);

		char* buffer = new char[len1 + 1];
		int idx = 0;

		for (int i = 0; i < len1; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				if (strVal[i] == second[j])
				{
					buffer[idx++] = strVal[i];
					break;
				}
			}
		}
		buffer[idx] = '\0';

		var result(buffer);
		delete[] buffer;
		return result;
	}

	var operator/(const var& obj) const
	{
		if (type == INT)
		{
			int value = obj.getInt();
			return var(value ? intVal / value : 0);
		}
		if (type == DOUBLE)
		{
			double value = obj.getDbl();
			return var(value ? dblVal / value : 0.0);
		}
		return *this - obj;
	}

	var& operator+=(const var& obj) { 
		return *this = *this + obj;
	}

	var& operator-=(const var& obj) { 
		return *this = *this - obj;
	}

	var& operator*=(const var& obj) { 
		return *this = *this * obj;
	}

	var& operator/=(const var& obj) { 
		return *this = *this / obj;
	}

	bool operator<(const var& obj) const
	{
		if (type == INT) return intVal < obj.getInt();
		if (type == DOUBLE) return dblVal < obj.getDbl();
		return isLessStr(strVal, obj.getStr());
	}

	bool operator>(const var& obj) const
	{
		if (type == INT) return intVal > obj.getInt();
		if (type == DOUBLE) return dblVal > obj.getDbl();

		return isLessStr(obj.getStr(), strVal);
	}

	bool operator<=(const var& obj) const { 
		return !(*this > obj);
	}

	bool operator>=(const var& obj) const { 
		return !(*this < obj);
	}

	bool operator==(const var& obj) const
	{
		if (type == INT) return intVal == obj.getInt();
		if (type == DOUBLE) return dblVal == obj.getDbl();

		return equalStr(strVal, obj.getStr());
	}



	bool operator!=(const var& obj) const { 
		return !(*this == obj);
	}

	operator int() const { 
		return getInt();
	}

	operator double() const { 
		return getDbl();
	}

	operator char* () const
	{
		String str = getStr();
		int len = length(str);

		char* result = new char[len + 1];
		for (int i = 0; i < len; i++) result[i] = str[i];
		result[len] = '\0';

		return result;
	}

	void Show() const
	{
		if (type == INT) cout << intVal << endl;
		else if (type == DOUBLE) cout << dblVal << endl;
		else
		{
			String temp = strVal;
			temp.print();
		}
	}

	void show() const { Show(); }
};