#include <iostream>

using namespace std;


const int ARRAY_SIZE = 10; // global constant
// constant allows you to change code by changing one line of code

void printArray(ostream& out, int myArray[], int size);
void readdataintoarray(istream& in, int myArray[], int &count )
;

// This will print the array to the ostream
// ostream out - the stream to prnt on
// int myArray - the array to be printed
// int size - how much stuff is in the array. 

int main()
{
	int myArray[ARRAY_SIZE]; // makes an array of 10 ints
	int count = 0;
	int x;

	cout << "Tell me a number to stuff into the array: ";

	readdataintoarray(istream& in, int myArray[], int &count);
	
	ofstream myoutputfile("arrayoutputstuff.txt");

	printArray(cout, myArray, count);

	myoutputfile.close();
	/*
	for ( int i = 0; i < count; i++)
	{
		cout << "myArray[" << i << "] = " << myArray[i] << endl;
		
		
		// don't ever do this in real code
		for (int i = 0, i<ARRAY_SIZE * 5, i++ << endl
			myArray[i] = i;

		for (int i =0; i < ARRAY_SIZE*5; i++)
		{
			cout << "myArray[" << i << "] = " << myArray[i] << endl;

		}
		*/






	

	return 0;
}




void printArray(ostream& out, int myArray[], int size)
{
	for ( int i = 0; i < size; i++)
	{			

		cout << "myArray[" << i << "] = " << myArray[i] << endl;

	}
	
}

void readdataintoarray(istream& in, int myArray[], int &count )
{
	int x;
	in >> x;
	while (!in.fail())
	{
		if ( count < ARRAY_SIZE)
		{
			myArray[count] = x; //store X at location count
			count++;
		}
		in >> x;
	}

}



