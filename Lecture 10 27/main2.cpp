#include "Data.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Data myData;
	myData.x = 1;
	myData.y = 1.0;

	Data myArrayOfData[10];

	for (int i = 0; i<10; i++)
	{
		myArrayOfData[i].x = i;
		myArrayOfData[i].y = i*1.0;
		myArrayOfData[i].goo = "goo";
		//---or ---- these next 4 lines do exactly what the previous 2 do
		myData = myArrayOfData[i];//get myData out of the array
		myData.x = i;
		myData.y = i*1.0;
		myArrayOfData[i] = myData; //stuff myData back in the array
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myArrayOfData[i].goo <<  "\t" <<  myArrayOfData[i].x << "\t" << myArrayOfData[i].y << endl;
	}

}