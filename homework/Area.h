#pragma once
#include <iostream>

using namespace std;

class Area
{
private:
	static int calcCount;

	static void incrementCount()
	{
		calcCount++;
	}

	static double customSqrt(double value)
	{
		if (value <= 0) return 0;

		double x = value;
		double root = 0;

		for (int i = 0; i < 100; ++i)
		{
			root = 0.5 * (x + (value / x));
			if (x == root) break;
			x = root;
		}
		return root;
	}

public:

	static double triangle(double base, double height)
	{
		incrementCount();
		return 0.5 * base * height;
	}

	static double triangle(double a, double b, double c)
	{
		incrementCount();
		double p = (a + b + c) / 2.0;
		return customSqrt(p * (p - a) * (p - b) * (p - c));
	}

	static double rectangle(double width, double height)
	{
		incrementCount();
		return width * height;
	}

	static double square(double side)
	{
		incrementCount();
		return side * side;
	}

	static double rhombus(double d1, double d2)
	{
		incrementCount();
		return (d1 * d2) / 2.0;
	}

	static double rhombusByHeight(double side, double height)
	{
		incrementCount();
		return side * height;
	}

	static int getCalculationCount()
	{
		return calcCount;
	}
};







class Point
{
private:
	int x;
	int y;
	static int count;

public:
	Point(int xVal, int yVal) : x(xVal), y(yVal)
	{
		count++;
	}

	Point() : Point(0, 0) {}

	Point(int val) : Point(val, val) {}

	void show() const
	{
		cout << "Point(" << x << ", " << y << ")" << endl;
	}

	static int getCount()
	{
		return count;
	}
};






class Fract
{
private:
	int numerator;
	int denominator;
	static int count;

public:
	Fract(int num, int den) : numerator(num), denominator(den == 0 ? 1 : den)
	{
		count++;
	}

	Fract() : Fract(0, 1) {}

	Fract(int num) : Fract(num, 1) {}

	void show() const
	{
		cout << numerator << "/" << denominator << endl;
	}

	static int getCount()
	{
		return count;
	}
};


class Student
{
private:
	const char* name;
	int age;
	static int count;

public:
	Student(const char* n, int a) : name(n), age(a)
	{
		count++;
	}

	Student() : Student("Yurii", 18) {}

	Student(const char* n) : Student(n, 33) {}

	void show()
	{
		cout << "Name: " << name << ", Age: " << age << endl;
	}

	static int getCount()
	{
		return count;
	}
};

