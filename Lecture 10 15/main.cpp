#include <iostream>

using namespace std;


const int ARRAY_SIZE = 10; // global constant
// constant allows you to change code by changing one line of code

int main()
{
	int myArray[ARRAY_SIZE]; // makes an array of 10 ints
	int count = 0;
	int x;

	cout << "Tell me a number to stuff into the array: ";
	cin >> x;
	while (!cin.fail())
	{
		if ( count < ARRAY_SIZE)
		{
			myArray[count] = x; //store X at location count
			count++;
		}
		cin >> x;
	}

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





		
	}

	return 0;
}