#include <iostream>
#include "Array.h"
#include "String.h"

using namespace std;

int main() {

    Array arr1(3);
    arr1.setRandom();
    cout << arr1 << endl;

    Array arr2 = -arr1;
    cout << arr2 << endl;

    Array arr3 = arr1 / 2;
    cout << arr3 << endl;

    ++arr1;
    cout << arr1 << endl;

    if (!arr1) {
        cout << "empty" << endl;
    }
    else {
        cout << "not empty" << endl;
    }



    String str1("privet");
    cout << str1 << endl;

    String str2 = str1 * 3;
    cout << str2 << endl;

    ++str1;
    cout << str1 << endl;

    str1[0] = 'X';
    cout << str1 << endl;

    if (!str1) {
        cout << "empty" << endl;
    }
    else {
        cout << "not empty" << endl;
    }

    return 0;
}