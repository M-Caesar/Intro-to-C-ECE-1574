#include "date.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	date d; // calls the constructor
	cout << "This is my date: ";
	cout << d.getMonth() << " " << d.getDay() << ", " << d.getYear() << "\n";

	date myOtherDate("Flupperberry", -100, 12212131231);
	cout << myOtherDate.getMonth() << " " << myOtherDate.getDay() << ", " << myOtherDate.getYear() << "\n";
}