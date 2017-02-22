#include "dynamic.h"

void dynamic( istream& in, ostream& out )
{
	int *x; // this is my pointer
	int size = 10; // this is how much I can store
	int count = 0; // this is how much I have stored so far. 


	x = new int [size];



	int data;
	in >> data;
	while (!in.fail() )
	{
		if (count == size)
		{
			grow(x, size);// make dat array bigger
		}

		{
			x[count] = data;
			count++;
		}
		in >> data;

			
	}
	out << "Size: " << size << endl;
	out << "Count: " << count << endl;

	for (int i=0; i< count; i++)
		out << x[i]<< endl;
}

void grow( int *&x, int &size) 
{
	int *temp = new int[size * 2];
	for (int i=0; i<size; i++)
		temp[i]=x[i];

	
	size *=2; 
	delete[] x; 
	x = temp;

	
	temp = NULL; 

}