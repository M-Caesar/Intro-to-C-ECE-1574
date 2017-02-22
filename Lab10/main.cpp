#include "lab10.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("commands.txt");

	readData( in, cout );
	in.close();

	//return 0;
}