#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <algorithm>
// includes the many streams, maths we use for later code


using namespace std;
// all the usings will allow me to 'use' certain callings and preset functions like cout




struct Widget
{
	string name;
	string desc;
	string part;
	double cost;
	int quantity;
	
}; 

// Definition of a structure that we call Widget. Widget being a quasi data type like structure 
// I later use to define a myArray[].
// Inside the struct of Widget, I have three strings, a double, and an int with a variable for each.


void inventory(istream& in, ostream& out);
// void will return something, with an input istream coulld in and an output ostream called out

void readfilename(string name, Widget myArray[], int &count);

void listCalc(istream& in, Widget myArray[], ostream& out, int &count );

void listCalc2(istream& in, Widget myArray[], ostream& out, int &count, string partNumber );

void saveCalc(istream& in, Widget myArray[], ostream& out, int &count  );

void buyCalc(istream& in,Widget myArray[], ostream& out, int &count);

void addCalc(istream& in,Widget myArray[], ostream& out, int &count);

// All of the functions defined here will accept an input that will be given to it. 