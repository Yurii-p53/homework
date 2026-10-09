
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <random>
#include "Windows.h"
#include "Node.h"
#include "Queue.h"
#include "Bus.h"

using namespace std;

void addTime(Queue<People>& p)
{
    size_t size = p.getSize();

    for (size_t i = 0; i < size; i++)
    {
        p.peek().addTime();
        p.ring();
    }
}

void addPassenger(Queue<People>& p, int N)
{
    p.enqueue(People());

    cout << "[+] New passanger" << endl;

    if (p.getSize() > N)
    {
        cout << "[!] Stop is full" << endl;
    }
}

void busArrived(Queue<People>& p, Queue<Bus>& bus,
    int& totalTime, int& count)
{
    Bus b = bus.peek();
    bus.dequeue();

    cout << "[!] -- Bus #" << b.getNumber() << " arrived --" << endl;

    while (p.getSize() > 0 && b.getFreePassenger() > 0)
    {
        totalTime += p.peek().getTime();
        count++;

        p.dequeue();
        b.takePassenger();
    }

    cout << "People: " << p.getSize() << endl;
}

int main()
{
    setlocale(LC_ALL, "");

    random_device rd;
    mt19937 gen(rd());

    Queue<Bus> bus = {};
    Queue<People> p;

    int N;
    int passengerTime;
    int busTime;
    int maxPassenger;
    int duration;
    int stopType;

    int totalTime = 0;
    int count = 0;
    int maxPeople = 0;

    cout << "Max people at stop: ";
    cin >> N;

    cout << "Time between passangers: ";
    cin >> passengerTime;

    cout << "Time between buses: ";
    cin >> busTime;

    cout << "Max free seats in bus: ";
    cin >> maxPassenger;

    cout << "Duration: ";
    cin >> duration;

    cout << "Stop type [1: central | 2: terminal]: ";
    cin >> stopType;

    if (N <= 0 || passengerTime <= 0 || busTime <= 0 ||
        maxPassenger <= 0 || duration <= 0 ||
        (stopType != 1 && stopType != 2))
    {
        cout << "Error" << endl;
        return 1;
    }

    int i = 0;

    while (i < duration)
    {
        if (i % passengerTime == 0)
        {
            addPassenger(p, N);
        }

        addTime(p);

        if (p.getSize() > maxPeople)
        {
            maxPeople = (int)p.getSize();
        }

        if (i % busTime == 0)
        {
            int free = uniform_int_distribution<int>(
                1, maxPassenger)(gen);

            string number;

            if (stopType == 1)
            {
                number = to_string(
                    uniform_int_distribution<int>(1, 3)(gen));
            }
            else
            {
                number = "T";
            }

            bus.enqueue(Bus(number, free));

            busArrived(p, bus, totalTime, count);
        }

        Sleep(1000);
        i++;
    }

    cout << "\n===============" << endl;

    cout << "Passengers served: " << count << endl;
    cout << "People remaining: " << p.getSize() << endl;
    cout << "Max people at stop: " << maxPeople << endl;
    cout << "Max people: " << N << endl;

    if (count > 0)
    {
        cout << "Waiting time: "
            << (double)totalTime / count
            << "sec" << endl;
    }
    else
    {
        cout << "No passengers." << endl;
    }

    return 0;
}