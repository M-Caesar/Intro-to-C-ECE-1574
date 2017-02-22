#include "Dynamic.h"

using namespace std;

int main()
{	
	ifstream in("data.txt")
	readData(in, cout);
	in.close();
}