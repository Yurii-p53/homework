#include <iostream>
#include "Var.h"

using namespace std;

int main()
{
    var a = 10;
    var b = 20.5;
    var c = "100";
    var str1 = "Hello, ";
    var str2 = "World!";

    var sum1 = a + b;
    var sum2 = a + c;
    var text = str1 + str2;

    sum1.show();
    sum2.show();
    text.show();

    return 0;
}