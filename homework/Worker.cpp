#include <iostream>
#include "Worker.h"

using namespace std;

int main() {

    int currentYear = 2026;
    int size = 0;

    cout << "vvedite kolichestvo rabotnikov: ";
    cin >> size;

    Worker* workers = Worker::createArray(size);

    for (int i = 0; i < size; i++) {
        cout << "\nvvod dannih dlya rabotnika #" << i + 1 << endl;

        char nameBuf[100];
        char posBuf[100];
        int year;
        double salary;

        cout << "FIO: ";
        cin >> ws;
        cin.getline(nameBuf, 100);

        cout << "Dolghnost: ";
        cin.getline(posBuf, 100);

        cout << "God postuplenia: ";
        cin >> year;

        cout << "Salary: ";
        cin >> salary;

        workers[i].setN(String(nameBuf));
        workers[i].setP(String(posBuf));
        workers[i].setY(year);
        workers[i].setS(salary);
    }

    int targetExp;
    cout << "\nVvedite zadanij stag (let): ";
    cin >> targetExp;
    cout << "\n=== Rezultat po stagu > " << targetExp << " ===" << endl;
    Worker::findByExperience(workers, size, currentYear, targetExp);

    double targetSalary;
    cout << "\nVvedite zadanuju zarplatu: ";
    cin >> targetSalary;
    cout << "\n=== Rezultat po z/p > " << targetSalary << " ===" << endl;
    Worker::findBySalary(workers, size, targetSalary);
        
    char targetPosBuf[100];
    cout << "\nVvedite zadanuju dolghnost: ";
    cin >> ws;
    cin.getline(targetPosBuf, 100);
    cout << "\n=== Rezultat po dolghnosti '" << targetPosBuf << "' ===" << endl;
    Worker::findByPosition(workers, size, String(targetPosBuf));

    delete[] workers;

    return 0;
}