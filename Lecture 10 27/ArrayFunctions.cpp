#include "ArrayFunctions.h"
void printArray(ostream& out, int myArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		out << "myArray[" << i << "] = " << myArray[i] << endl;
	}
}

void readDataIntoArray(istream& in, int myArray[], int &count )
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
}