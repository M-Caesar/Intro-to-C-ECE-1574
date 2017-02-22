#include <string>
#include <iostream>
using std::istream;
using std::string;

struct Data
{
	int x;
	double y;
	string goo;
	void setX(int newx);//we can do this
};

void readData(istream& in, Data data[], int &count);