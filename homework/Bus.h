
#pragma once

#include <iostream>
#include <string>

using namespace std;

class People
{
    int time;

public:
    People()
    {
        time = 0;
    }

    void addTime()
    {
        time++;
    }

    int getTime() const
    {
        return time;
    }
};

class Bus
{
    string number;
    int freePassenger;

public:
    Bus()
    {
        number = "0";
        freePassenger = 0;
    }

    Bus(string n, int free)
    {
        number = n;
        freePassenger = free;
    }

    string getNumber() const
    {
        return number;
    }

    int getFreePassenger() const
    {
        return freePassenger;
    }

    void takePassenger()
    {
        if (freePassenger > 0)
        {
            freePassenger--;
        }
    }
};