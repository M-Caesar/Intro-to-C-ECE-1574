#include <iostream>
#include "lab8.h"
#include <fstream>
using namespace std;
const int ARRAY_SIZE = 10; //this is a global constant
void readInts( istream& in, ostream& out )
{
	int myArray[ARRAY_SIZE];//make an array of 10 ints
	int count = 0; //how much stuff is in my array
	int size = 0;
	size = readDataIntoArray(in, myArray, count);
	out << "Index Value \n";
	for (int i = 0; i < 10; i++)
	{
		out << i << " " << myArray[i] << endl;
	}
}

	int readDataIntoArray(istream& in, int myArray[], int &count )
	{
		int x;
		in >> x;
		while (!in.fail())
		{
			if (count < ARRAY_SIZE && count >= 0)
			{
				myArray[count] = x;//store X at location count
				count++;
			}
			in >> x;
		}
		return count;
	}

	