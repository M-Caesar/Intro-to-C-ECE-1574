#include "equivResist.h"
using namespace std; //for additional uses below

void equivalentResistance( istream& in, ostream& out )
{
	
	
	double resistor; // initializes a variable resistor that is a 'double' floating point
	
	string name;
	
	string input;
	

	double count1 = 0; // this will operate as the 'answer' to the equation
	
	
	
	cout << "Please tell me if this is Parallel or Serial: "; // outputs a cout that won't be read by webcat but for user
	in >> name; //this will read the word of parallel or series to identify the true calculation
	
	cout << "Please tell me the resistor value(s): "; // outputs a cout that won't be read by webcat but for user
	in >> resistor; //prime that inputs a value for resistor
	while( !in.fail() )// beginning of while statement with !in.fail to make sure there is a real value. 
	{
	
		if (name == "Series" || name == "series" || name == "s" || name == "S") // sets it so that series can be any name that Webcat recognizes. 
		{
			count1 = count1 + resistor; // series is an easy calculation of just adding it up. So this can just add up the values to count1 which is our answer. 
			cout << "Please tell me the resistor value(s): "; // outputs a cout that won't be read by webcat but for user
			
		}
		else // if it isn't series, the while statement will push down to the else statement. 
		{
		count1 = count1 + 1.0/resistor; // formulal for adding the answer up in parallel. There is no need of setting up an identification 
										// for parallel as anything 'else' goes here. 
			cout << "Please tell me the resistor value(s): "; // outputs a cout that won't be read by webcat but for user
		
		}
		in >> resistor; //reprime so that the values get re-inputed.
	} // while statement and main code ends. 
	
	
	out <<"Equivalent Resistance: \n" // outputs a cout that won't be read by webcat but for user
	<< "Resistors in: " << name  // just cout statements that have the 'name' setup. 
	<< "\nResistance: ";
	if (name == "Series" || name == "series" || name == "s" || name == "S") // the output for the real answer. 
	{
		out << count1 << " Ohms" << endl; // if the answer was series, it will output this. 
	}
	else
	{
		out << 1/count1 << " Ohms" << endl; // the answer was parallel so it will output this. 
	}


}


