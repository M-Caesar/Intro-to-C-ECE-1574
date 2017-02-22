#include <iostream>
#include <string>
using namespace std;

int main()
{
	int firstnumber; //this is the first number
	int secondnumber; // this is the second number. 
	int remainder; // this is the remainder of integer division
					// I'm seeing if this is a factor	
					// of the first number
	cout << "Enter a first number: " << endl;
	cin >> firstnumber;
	cout << endl;
	cout << "Enter a second number: ";
	cin >> secondnumber;
	cout << endl;
	
	remainder = firstnumber % secondnumber; // get the remainder
	
	cout << remainder << endl;
	if ( remainder == 0 );  //if remainder is equal to 
	// let's check the remainder and see if it's zero
	{	
		cout << "The number " << secondnumber << " is a factor "
			<< " for " << firstnumber << endl;
		cout << "The other factor is " << firstnumber / secondnumber << endl;
	}
	else
{	
		cout << "The number " << secondnumber << " is not a factor "
		<< " for " << firstnumber << endl;
}
		
	return 0;
}