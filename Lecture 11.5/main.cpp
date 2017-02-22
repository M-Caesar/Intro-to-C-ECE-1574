#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <algorithm>

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

	// new gives it memory

	x = new int;

	// de refrenced it here and assigned it the value of 10
	*x = 10;
	cout << "x is " << x << endl;
	cout << "y is " << y << endl;

	cout << "*x is " << *x << endl;
	cout << "&y " << &y << endl;

	cout << "&x" << &x << endl;

	// frees or releases x back to the system for use, b
	delete x;
	// you cannot access x again until you give it more memory. 

	// dynamic allocation of an array of ints

	x = new int[10];

	for (int i=0; i < 10; i++)
		x[i] =i;
	for (int i=0; i < 10; i++)
		cout << i << " " << x[i] << endl;

	// frees or releases x back to the system for use, 

	delete[] x;


	return 0;

}