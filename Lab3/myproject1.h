#include "equivResist.h"
using namespace std;

void equivalentResistance( istream& in, ostream& out )
{
	//write my code;
	//use in not cin;
	//use out not cout;
	
	//sets a string to read if it is parallel or serial
	double resistor; // this is a double float for the resistor
	
	string name;
	
	
	
	double count1 = 0;
	
	
	
	cout << "Please tell me if this is Parallel or Serial: ";
	in >> name; //this will read the word
	

	cout << "Please tell me the resistor value(s): ";
	in >> resistor; //prime
	while( !in.fail() )//test1
	{
	
		if (resistor == 0)
		{
			
			cout << "Please tell me the resistor value(s): ";
			return 0;
		}
		else
		{
		count1 = count1 + 1.0/resistor;
			cout << "Please tell me the resistor value(s): ";
			
		}
		in >> resistor; //reprime
	}
	out <<"Equivalent Resistance: \n" 
	<< "Resistors in: " << name 
	<< "\nResistance: ";
	if (name == "Series" || name == "series" || name == "s" || name == "S")
	{
		out << count1 << " Ohms" << endl;
	}
	else
	{
		out << 1/count1 << " Ohms" << endl;
	}
//*you may use cout for any output you want to see;
//web-cat will not "see" cout;
//make sure the output that web-cat watns goes to out;

}


