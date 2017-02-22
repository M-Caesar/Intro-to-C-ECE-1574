#include <iostream>
#include <fstream>
#include <string>
//#include "lab9.h"
using std::cout;
using std::cin;
using std::endl;
using namespace std;

struct basic
{
	
	string name;
	double number;
	
	
};

int main()
{
    struct basic;
    basic.number = 10.5;
    basic.name = "this is my name";
    cout << "The number is: " << basic.number << endl;//this should say "The number is: 10.5"
    cout << "The name is: " << basic.name << endl; //this should say, "The name is: this is my name"

}