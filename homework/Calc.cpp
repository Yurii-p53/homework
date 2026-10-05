#include "Calc.h"
#include <iostream>
#include <string>
#include "Struct.h"

using namespace std;

int main() {
	Calc calculator("3 + 5 * 2 - 8 / 4");

	cout << calculator.getResult() << endl;
}