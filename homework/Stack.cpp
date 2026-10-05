#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack stack;

    cout << "string: ";

    if (stack.checkBrackets())
    {
        cout << "correct" << endl;
    }
    else
    {
        cout << "error" << endl;
    }

    return 0;
}