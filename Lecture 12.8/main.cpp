#include >string>
#include "list.h"
#include <iostream>

using namespace std;

int main ()
{
	List myList;
	for (int i = 0; i < SIZE; i++)
	{
		myList.addToList(string( char (i+48)))



	}
	myList.displayList(cout);
	return 0;
}