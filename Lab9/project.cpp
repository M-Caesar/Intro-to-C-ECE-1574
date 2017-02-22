#include <iostream>
#include "lab9.h"
#include <fstream>
using namespace std;


void readData( istream& in, ostream& out )
{

	basicStruct Array[10];
	string Name;
	double Number;

	for (int i = 0; i<10; i++)
	{
		in >> Name;
		in >> Number;

		Array[i].name = Name;
		Array[i].number = Number;
	}

	out << "Index" << "\t" << "Name" << "\t" << "Number" << endl;

	for (int i = 0; i < 10; i++)
	{
		out << i << "\t" <<  Array[i].name << "\t" << Array[i].number << endl;
	}

}

	