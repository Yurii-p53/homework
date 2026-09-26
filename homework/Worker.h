#pragma once

#include <iostream>
#include "String.h"

using namespace std;

enum type {
};

class Worker {
private:
    String name;
    String pos;
    int year;
    double salary;

public:
    Worker() : name("Igor"), pos("None"), year(2020), salary(0.0) {}

    explicit Worker(const char* name, const char* pos = "Worker", int year = 2023, double salary = 1000.0) : name(name), pos(pos), year(year), salary(salary) {}

    Worker(const Worker& obj) : name(obj.name), pos(obj.pos), year(obj.year), salary(obj.salary) {}

    Worker& operator=(const Worker& obj) {
        if (this == &obj) {
            return *this;
        }
        name = obj.name;
        pos = obj.pos;
        year = obj.year;
        salary = obj.salary;
        return *this;
    }

    void setN(const String& name) { 
        this->name = name;
    }

    void setP(const String& pos) { 
        this->pos = pos;
    }

    void setY(int year) { 
        this->year = year;
    }

    void setS(double salary) { 
        this->salary = salary;
    }

    const String& getN() const { 
        return name;
    }

    const String& getP() const { 
        return pos;
    }

    int getY() const {
        return year;
    }

    double getS() const { 
        return salary;
    }

    int getExp(int currentYear) const {
        return currentYear - year;
    }

    void print() const {
        cout << "FIO: ";
        name.print();
        cout << "Dolghnost: ";
        pos.print();
        cout << "Salary: " << salary << " $" << endl;
        cout << "God postuplenia: " << year << endl;
        cout << "------------------------" << endl;
    }

    static Worker* createArray(int size) {
        return new Worker[size];
    }

    static void findByExperience(const Worker* arr, int size, int currentYear, int targetExp) {
        for (int i = 0; i < size; i++) {
            if (arr[i].getExp(currentYear) > targetExp) {
                arr[i].print();
            }
        }
    }

    static void findBySalary(const Worker* arr, int size, double targetSalary) {
        for (int i = 0; i < size; i++) {
            if (arr[i].getS() > targetSalary) {
                arr[i].print();
            }
        }
    }

    static void findByPosition(const Worker* arr, int size, const String& targetPos) {
        for (int i = 0; i < size; i++) {
            arr[i].print();
        }
    }
};