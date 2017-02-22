#include "runner.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("commands.txt");

	runRace( in, cout );
	in.close();

}