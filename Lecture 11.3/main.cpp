#include <iostream>

using namespace std;

int main()
{
	int *x;// x is a pointer to an int;

	int y;

	x = &y;

	y = 7;

	cout << "x is " << x << endl;
	cout << "y is " << y << endl;

	cout << "*x is " << *x << endl;
	cout << "&y " << &y << endl;

	cout << "&x" << &x << endl;

	// dynamic allocation
	// new is a pre-declared name

	x = new int;


	*x = 10;
	cout << "x is " << x << endl;
	cout << "y is " << y << endl;

	cout << "*x is " << *x << endl;
	cout << "&y " << &y << endl;

	cout << "&x" << &x << endl;

	delete x;

	x = new int[10];

	for (int i=0; i < 10; i++)
		x[i] =i;
	for (int i=0; i < 10; i++)


	return 0;

}