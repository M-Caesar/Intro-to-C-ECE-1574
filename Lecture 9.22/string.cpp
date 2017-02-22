#include "stringfunction.h"

void stringFunction (istream& in, ostream& out)
{
	string word;
	int sum = 0; // this is my sum of the words in my sentence
	in >> word; // read in a word and priming
	
	while ( !in.fail() ) //fail
	{
		sum++; // sum = sum +1 can also work
		if ( word == "string" || word == "today" )
			out << "YEEAAAAAHAHAHAHA" << endl;
		else
			out << word << endl;
		
		in >> word; //reprime
	}
	out << "This sentence had: " << sum << "words" << endl;
}

