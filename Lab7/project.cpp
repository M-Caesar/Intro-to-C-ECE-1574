#include "convert.h"
using namespace std;

void stringNumberConvert( istream& in, ostream& out )

{

	string initial;
	int number;
    string word;
	//string finalCN;
	//string finalCS;
	string final;
	int final2;
	//string final2;
	//cout << "Is this toString or toNumber?";

	in >> initial;



	while ( !in.fail() )
	{
		if (initial == "toString")
		{
			in >> number;
			
			final = convertNumber ( number );
			//final1 = finalCN;

			out << "Converted from Number to String" << endl << "Number: " << number << endl << "String: " << final << endl;


		}
		else
		{
			in >> word;	
            final2 = convertString (word );
            //final2 = finalCS;

            out << "Converted from String to Number" << endl << "String: " << word << endl << "Number: " << final2 << endl;
		}
		in >> initial;
		
	}



}

	string convertNumber(int number )
	{
		
		string results;
		
		if (number == 1)
		{
			results = "one";
		}
		else if ( number == 2)
		{
			results = "two";
		}
		else if ( number == 3)
		{
			results = "three";
		}
		else if ( number == 4)
		{
			results = "four";
		}
		else if ( number == 5)
		{
			results = "five";
		}
		else if ( number == 6)
		{
			results = "six";
		}
		else if ( number == 7)
		{
			results = "seven";
		}
		else if ( number == 8)
		{
			results = "eight";
		}
		else if ( number == 9)
		{
			results = "nine";
		}
		else if ( number == 0)
		{
			results = "zero";
		}
		else 
		{
			results = "error";
		}
		

		return results;
		
			

	}

	int convertString(string word )
	{
		int results;

		if (word == "one")
		{
			results = 1;
		}
		else if ( word == "two")
		{
			results = 2;
		}
		else if ( word == "three")
		{
			results = 3;
		}
		else if ( word == "four")
		{
			results = 4;
		}
		else if ( word == "five")
		{
			results = 5;
		}
		else if ( word == "six")
		{
			results = 6;
		}
		else if ( word == "seven")
		{
			results = 7;
		}
		else if ( word == "eight")
		{
			results = 8;
		}
		else if ( word == "nine")
		{
			results = 9;
		}
		else if ( word == "zero")
		{
			results = 0;
		}
		else 
		{
			results = -1;
		}
		
		
		
		return results;
	}
	

