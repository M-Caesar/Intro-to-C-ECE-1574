#include "resistors.h"
using namespace std;

void computeResistance( istream& in, ostream& out )
{
	
	double resistor; // this is a double float for the resistor
	double resistor2;
	double resistor3;
	
	//int TotalSet=3;
	int initial=0;
	
	int count = 0;
	double answer;
	double answer2;
	double answer3;

	//cout << "Please tell me the resistor value(s): ";
	 //prime
	 in >> resistor >> resistor2 >> resistor3;
	 
	while(count <= 3 )//test1
	{
		in >> resistor;
		answer = answer + resistor;
		count = count + 1;
		
	
		//answer =  1.0/(1/resistor);
		//answer2 = 1.0/(1/resistor2);
		//answer3 = 1.0/(1/resistor3);
		//in >> resistor >> resistor2 >> resistor3; //reprime
	}
	
	count = 0;
	
	while(count <= 3 )//test1
	{
		in >> resistor2;
		answer2 = answer2 + resistor2;
		count = count + 1;
		
	}

	count = 0;
	
	while(count <= 3 )//test1
	{
		in >> resistor3;
		answer3 = answer3 + resistor3;
		count = count + 1;
		
	}
	
	count = 0;
	out << 1/answer << endl;
	out << 1/answer2 << endl;
	out << 1/answer3 << endl;
	//out << answer2 << endl;;
	//out << answer3 << endl;
	

/*	if (count1 == 0);
	{
		out << "--error--";
	}
	
		out << 1/count1;
	
	
}
*/
}
