#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <algorithm>




using namespace std;

struct Widget
{
	string last;
	string first;
	string bib;
	string sex;
	int clock; 
	int chip;

};

// Definition of a structure that we call Widget. Widget being a quasi data type like structure 
// I later use to define a myArray[].
// Inside the struct of Widget, I have four strings and two ints for the various inputs I'll be giving it

void runRace( istream &in, ostream &out );
// void will return something, with an input istream coulld in and an output ostream called out


void readfilename(string name, Widget *&myArray, int &count, int &size);

void namefunction(istream& in, Widget *myArray, ostream& out, int &count, int &size,string command );

void placefunction(istream& in, Widget *myArray, ostream& out, int &count,string command );

void bibfunction(istream& in, Widget *myArray, ostream& out, int &count,string command );

void grow( Widget *&myArray, int &size);

// All of the functions defined here will accept an input that will be given to it. 