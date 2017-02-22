#define _USE_MATH_DEFINES
//#define WIN32_WINNT 0x0501
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using std::string;
using namespace std;
using std::istream;
using std::ostream;
using std::setprecision;
using std::fixed;
using std::showpoint;

using std::setw;

void encryptDecrypt( istream& in, ostream& out );

string encrypt(string input);
string decrypt(string input);