#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;



void myAwesomeFunction( istream&, ostream& out);

double readNumbers(istream& in, string &path);

int main()

{
	myAwesomeFunction(cin,cout);
}


void myAwesomeFunction( istream&, ostream& out)
{


	char c;
	string path;

	c = in.peek(); //look at the next character

	while( !in.fail())
	{
		if (isalpha(c) && c == 'p' || c == 'P')// will look at c, will return true if it is an alphabetic letter.
												// Then check if lower or uppercase p. Character is a letter so single quote
												// string is always double quote as as many characters
		{
			// go call some function when this happens. 
			// passing in the information. 

			//below won't work

			in.get();


		}
		else
		{
			// go call soething else

			double d = readNumbers(in, path);


			in.get();


		}

		while ( isspace(in.peek())) // eat white space 
			in.get();




		c = in.peek();
	}
}
}


//the series stuff. 
double readNumbers(istream& in, string &path)

{
	char c = in.peek(); 

	if ( isalpha(c))
		in.get();
	while (isspace( in.peek()))
			in.get();


	double resistor;
	double answer;
	while (!in.fail()) && !isalpha(c))
	{
		char buffer[50]; //gives space for 50 characters. Long enough
		in >> resistor;

		answer = answer + resistor;

		sprintf(buffer, "%f", d) // take the double, use the floating point format, and stick it into the buffer. 
		
		path = path + string(buffer);

		while (isspace( in.peek()))
			in.get();

	}
	return d;


}