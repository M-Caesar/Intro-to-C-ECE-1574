#include "Address.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using namespace std;
using std::endl;

int main()
{
	Address a;
	cout << "I just made an address with both the names and address being \"\""<<endl;
	a.setFirstName( "Dave" );
	cout << "I just set the first name to \"Dave\""<< endl;
	cout << "Here's the first name now: " << a.getFirstName() << endl
	<< "Is it \"Dave\"?"<< endl;
	a.setLastName( "McPherson" );
	cout << "I just set the last name to \"McPherson\""<< endl;
	cout << "Here's the last name now: " << a.getLastName() << endl
	<< "Is it \"McPherson\"?"<< endl;
	a.setAddress( "123 Sunshine Road" );
	cout << "I just set the address to \"123 Sunshine Road\""<< endl;
	cout << "Here's the address now: " << a.getAddress() << endl
	<< "Is it \"123 Sunshine Road\"?"<< endl;
	cout << endl << "If you answered yes to the above questions, then"
	<< " your Address clss is probably working." 
	<< endl
	<< "If you had to modify main to get this to work, then your"
	<< " Address class probably doesn't work right." << endl;
	return 0;
}
