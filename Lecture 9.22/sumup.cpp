#include "sumup.h"

void sumupnumbers( istream& in, osteam& out)

{
	int sum = 0;
	int number; // this is what I read in
	
	in >> number;
	while( !in.fail() )
	{
		sum = sum + number;
		
		in >> number;
	}
	out << "The sum of the numbers is: " << sum << endl;
}
