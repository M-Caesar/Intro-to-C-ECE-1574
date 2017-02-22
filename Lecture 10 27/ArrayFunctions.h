#include <iostream>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

const int ARRAY_SIZE = 10; //this is a global constant



void printArray(ostream& out, int myArray[], int size);

void readDataIntoArray(istream& in, int myArray[], int &count);
