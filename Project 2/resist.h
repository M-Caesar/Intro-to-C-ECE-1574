#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <algorithm>
// includes the many streams, maths we use for later code

using std::string;

using std::ifstream;
using std::cout;
using std::endl;
using std::isspace;
using namespace std;
using std::cin; 

// all the usings will allow me to 'use' certain callings and preset functions like cout

void computeResistance( istream& in, ostream& out );
// void will return something, with an input istream coulld in and an output ostream called out


double series(istream& in, string &path);
double parallel(istream& in, string &path);
// the series and parallel functions will be doubles. What is inside them will first be an input stream called in again
// as that is what computeResistance had initially. The secondary will be a string with a path that will be changing. 