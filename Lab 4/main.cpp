#include "calculate.h"
#include <iostream>

using std::cout;
using std::cin;

int main()
{
    cout << "Please enter a number of trig commands followed by an angle in degrees.  For example: sin 45 cos 45 tan 45: \n";
    calculate( cin, cout );
    return 0;
}