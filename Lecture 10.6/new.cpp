//Output File Streams

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>



using namespace std;

//---
//Insertion or >>

//cout << x; // data flowing from x into cout. 
//out.open( "myOutputfile.txt" ); // open a file for writing. 

//----
//I/O Manipulation library

//#include <iomanip>

//setw (); // sets how many characters wide the output should be. You must use this each time you want to set te width. 
//setprecision (); // sets how many decimal places a decimal number should have. 
//-----

int main ()
{
	ifstream in;
	ofstream out;

	int totalCharacters = 0;
	int digits = 0;
	int letters = 0;
	int spaces = 0;
	int punct = 0;
	

	string file;
	string file2;

	char c;

	cout << "Tell me the name of the input file: ";
	cin >> file;
	cout << endl;

	cout << "Tell me the name of the output file: ";
	cin >> file2;
	cout << endl;

	in.open ( file.c_str());
	out.open ( file2.c_str());

	c = in.get();
	while( !in.fail() )
	{
		totalCharacters++;
		if ( isdigit ( c ))
		{
			digits = digits + 1; // same as digits++



		}
		else if ( isalpha (c))
		{
			letters++;
		}
		else if ( isspace (c))
		{
			spaces++;
		}
		else if ( ispunct (c))
		{
			punct++;
		}
		c = in.get();

	}

	out << "Total Cahracters: " << setw (10) << totalCharacters << endl;
	out << "Digits: " << setw (10) << digits << endl;
	out << "Letters: " << setw (10) << letters << endl;
	out << "Spaces: " << setw (10) << spaces << endl;
	out << "Punctuation: " << setw (10) << punct << endl;

	double digitPercent = (1.0 * digits) / totalCharacters; // 1.0 is a double, and digits is an int. 
															//If this was an init, it woud get me 0. Thus using a double multiplier,
															// I get mixed math so this can work. But we can also change int up top 
															//to double
	double letterPercent = (1.0 * letters) / totalCharacters;
	double spacePercent = (1.0 * space) / totalCharacters;
	double punctPercent = (1.0 * punct) / totalCharacters;

	out << setprecision(2) << fixed << showpoint; // tells how many decimal places to display. Not like setw. You only HAVE TO DO IT 1 TIME.
													// fixed and showpoint are addons that change set precision to just 2 decimals after
													//setprecision would display the first or last two NON ZERO decimals. 
													// fixed says don't use scientific notation
													//showpoint means always show the decimal point. 
	out << "Digits % " << digitPercent << endl;
	out << "Letter % " << letterPercent << endl;
	out << "Space % " << spacePercent << endl;
	out << "Punctuation % " << punctPercent << endl;








}