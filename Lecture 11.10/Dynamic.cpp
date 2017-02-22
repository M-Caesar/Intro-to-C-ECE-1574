#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <algorithm>



#include "Dynamic.h"

using namespace std;





void readData( istream& in, ostream& out)
{
	int *x; // this is my pointer
	int size = 10; // this is how much I can store
	int count = 0; // this is how much I have stored so far. 

	// let's give x it's memory

	x = new int [size];

	// allows it to have 10 int spaces
	// until we release the variable we will use it like a normal array

	int data;
	in >> data;
	while (!in.fail() )
	{
		if (count == size)
		{
			grow(x, size);// make dat array bigger
		}

		{
			x[count] = date;
			count++;
		}
		in >> data;

			
	}

	for (int i=0; i< count; i++)
		out << i << "\tx[i]" << x[i]<< << endl;

}
// growing is a 4 step process
// 1: make a new larger array
// 2: copy the elements fromt he old array into the new array
// 3: make the size biggr
// 4: point the old array to the new array
// 5: Clean up your memory
void grow( int *&x, int &size); // firs tthing given is a pointer. Second thing given is a paramter of size that shows how big it is
{
	int *temp = new int[size * 2];
	for (int i=0; i<size; i++)
		temp[i]=x[i];

	
	size *=2; // size = size *2
	delete[] x; // gives back x's memory
	x = temp;

	// housekeeping
	temp = NULL; // null is no address

	// DON'T EVER EVER EVER EVER EVER EVER EVER DO THE BELOW
	//  delete [] temp;

	// Always just assign it to NULL instead of deleting it. 
}

void sort(int x[], int count)
{
	for (int i= 0; i < count; i++)
	{
		for (int j=i; j < count; j++)
			if(x[i] < x[j])
			{
				int temp = x[i];
				x[i]=x[j];
				x[j]=temp

			}
	}
}