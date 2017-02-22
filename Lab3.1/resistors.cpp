#include "resistors.h"
using namespace std;

void computeResistance( istream& in, ostream& out )
{
	double resistor; // this is a double float for the resistor
	double resistor2;
	double resistor3;
	
	double answer;
	double answer2;
	double answer3;

	cout << "" << endl;
	cout << "Tell me the 3 resistor values.\n" << endl;
	in >> resistor >> resistor2 >> resistor3; // prime
	
	while ( !in.fail() )
	{
		if ( resistor == 0 || resistor2 == 0 || resistor3 == 0 )
			out << "--error--";
		else
		{
			answer = 1 / ( 1/resistor + 1/resistor2 + 1/resistor3 );
			cout << "" << endl;
			out << answer;
			cout << "" << endl;
			cout << "" << endl;
		}
		
	in >> resistor >> resistor2 >> resistor3;
	
	}
	
	

}


