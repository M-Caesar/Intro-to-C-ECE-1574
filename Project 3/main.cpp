#include "inventory.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("commands.txt");

	inventory( in, cout );
	in.close();

	//return 0;
}
	

