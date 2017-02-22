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


void readInts( istream& in, ostream& out );

int readDataIntoArray(istream& in, int myArray[], int &count );