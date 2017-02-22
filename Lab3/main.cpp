#include "resistors.h"
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;

int main()
{
	ifstream in("input.txt");

	computeResistance( in, cout );
	
	in.close();
	return 0;
}

