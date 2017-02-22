#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



struct Widget
{
	
	string name;
	double number;
	
	
}; 

void readData( istream& in, ostream& out);

void readfilename(string file, Widget myArray[], int &count);


void listCalc2(istream& in, Widget myArray[], ostream& out, int &count, string name );
void listCalc(istream& in,Widget myArray[], ostream& out, int &count, double number );

