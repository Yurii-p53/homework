#include <iostream>
#include "Area.h"

using namespace std;

int Area::calcCount = 0;


int Point::count = 0;
int Fraction::count = 0;
int Student::count = 0;




int main()
{
	cout << "square area (5): " << Area::square(5) << endl;
	cout << "rectangle area (4x6): " << Area::rectangle(4, 6) << endl;
	cout << "triangle area (base 3, height 4): " << Area::triangle(3, 4) << endl;
	cout << "triangle Heron area (3, 4, 5): " << Area::triangle(3, 4, 5) << endl;
	cout << "rhombus area (d1 8, d2 6): " << Area::rhombus(8, 6) << endl;
	cout << "rhombus area (side 5, height 4): " << Area::rhombusByHeight(5, 4) << endl;

	cout << "\nCount: " << Area::getCalculationCount() << endl;

	cout << "---------------------------------" << endl;


	Point p1;
	Point p2(5);
	Point p3(10, 20);

	Fract f1;
	Fract f2(5);
	Fract f3(3, 4);

	Student s1;
	Student s2("Ivan");
	Student s3("Oleg", 20);	

	cout << "points: " << Point::getCount() << endl;
	cout << "fractions: " << Fract::getCount() << endl;
	cout << "students: " << Student::getCount() << endl;

	s1.show();
	s2.show();
	s3.show();

	return 0;
}