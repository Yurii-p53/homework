#include <iostream>
#include <vector>

using namespace std;

class Train
{
    int number;
    string time;
    string station;

public:

    Train()
    {
        number = 0;
        time = "";
        station = "";
    }

    void input()
    {
        cout << "Enter train number: ";
        cin >> number;

        cout << "Enter departure time: ";
        cin >> time;

        cout << "Enter destination station: ";
        cin >> station;
    }

    void print()
    {
        cout << "Number: " << number << endl;
        cout << "Departure time: " << time << endl;
        cout << "Destination station: " << station << endl;
    }

    int getNumber()
    {
        return number;
    }
};

class Station
{
    vector<Train> trains;

public:

    void addTrain()
    {
        Train t;
        t.input();

        trains.push_back(t);
    }

    void print()
    {
        if (trains.empty())
        {
            cout << "No trains!" << endl;
            return;
        }

        for (int i = 0; i < trains.size(); i++)
        {
            cout << "\nTrain " << i + 1 << endl;
            trains[i].print();
        }
    }

    void findTrain()
    {
        int number;
        bool found = false;

        cout << "Enter train number: ";
        cin >> number;

        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getNumber() == number)
            {
                trains[i].print();
                found = true;
            }
        }

        if (!found)
            cout << "Train not found!" << endl;
    }
};

int main()
{
    Station station;

    int choice;

    do
    {
        cout << "\n1. Add train" << endl;
        cout << "2. Print all trains" << endl;
        cout << "3. Find train" << endl;
        cout << "0. Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            station.addTrain();
            break;

        case 2:
            station.print();
            break;

        case 3:
            station.findTrain();
            break;

        case 0:
            cout << "Exit!" << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}