#pragma once

#include <iostream>

using namespace std;

class Prinable
{
public:

	virtual void print() = 0;
};

class Animal : public Prinable
{
	string name;
	int age;

public:
	Animal(string n, int a) : name(n), age(a) {}

	virtual ~Animal() { cout << "Destr Animal" << endl; }

	string getName() { return name; }

	int getAge() { return age; }

	virtual string getType() = 0;

	virtual string getVoice() = 0;

	void print()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Type: " << getType() << endl;
		cout << "Voice: " << getVoice() << endl;
	}
};


class Cat : public Animal
{
public:
	Cat(string n, int a) : Animal(n, a) {}

	~Cat() { cout << "Destr Cat" << endl; }

	virtual string getType() override { return "Cat"; }

	virtual string getVoice() override { return "Meow meow"; }
};


class Dog : public Animal, public Prinable
{
public:
	Dog(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Dog"; }

	virtual string getVoice() override { return "Woof woof"; }

	virtual void print() override
	{
		cout << "Dog: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Type: " << getType() << endl;
		cout << "Voice: " << getVoice() << endl;
	}
};


class Parrot : public Animal, public Prinable
{
public:
	Parrot(string n, int a) : Animal(n, a) {}

	virtual string getType() override { return "Parrot"; }

	virtual string getVoice() override { return "Squawk"; }
};
