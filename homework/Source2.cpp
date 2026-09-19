#include <iostream>
#include "Reservoir.h"
#include <Windows.h>


using namespace std;

int main()
{
    Reservoir r1("черное море", 400, 115, 2212, SEA);
    Reservoir r2("азовское море", 200, 380, 14, SEA);
    Reservoir r3("свитязь", 48, 78, 58.4, LAKE);

    cout << "водоемы" << endl;
    r1.print();
    r2.print();
    r3.print();

    cout << "\nпроверка" << endl;
    if (r1.isSameType(&r2))
    {
        cout << r1.getName() << " и " << r2.getName() << " одного типа" << endl;
    }

    cout << "\nсравнение" << endl;
    if (r1.isAreaGreater(&r2))
    {
        cout << r1.getName() << " больше чем " << r2.getName() << endl;
    }

    
    r1.isAreaGreater(&r3);

    Reservoir copy;
    copy.copyFrom(&r1);
    copy.print();

    return 0;
}