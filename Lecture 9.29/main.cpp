#include "oddOrEven.h"
#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using namespace std;
using std::endl;
using std::string;

int main ()
{
	int number;
	cout << "Tell me an even number: ";
	cin >> number;
	cout << endl;

	while ( !oddOrEven ( number) )
	{
		cout << "I asked for an even number";
		cout << endl << "Please tell me an even number: \n";
		cout << endl;
		cin >> number;
		cout << endl;
	}

	cout << "Thank you" << endl; 
	
	
	main();
	//return 0;
}

