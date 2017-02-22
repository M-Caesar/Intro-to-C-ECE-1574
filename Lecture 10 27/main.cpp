
#include "ArrayFunctions.h"


int main()
{
	int myArray[ARRAY_SIZE];//make an array of 10 ints
	int count = 0; //how much stuff is in my array

	ifstream in("inputStuff.txt");

	readDataIntoArray(in, myArray, count);
	in.close();
	ofstream myOutputfile("arrayOutputStuff.txt");
	printArray(myOutputfile, myArray, count);
	myOutputfile.close();
	

	return 0;
}

